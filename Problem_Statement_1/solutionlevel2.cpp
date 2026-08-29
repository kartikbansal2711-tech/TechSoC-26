#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include <cmath>
#include <iomanip> 
using namespace std;


int main(){
    string n;
    cin>>n;

    int R,C,G;
    cin>>R>>C;
    if(n=="classify"){
        G=10;
    }
   
    
    else{
    cin>>G;}
    int intialpop=0;
     int  cnt=0;
vector<vector<char>> arr(R,vector<char>(C));
vector<int> rcoo;
vector<int> ccoo;
   

    //counting the initial population and assigning values in 2d array
    for(int i=0;i<R;i++){
        string s;
        
        cin>>s;
       
        for(int k=0;k<C;k++){
            arr[i][k]=s[k];
             if(s[k]=='#'){
                cnt++;
                rcoo.push_back(i);
                ccoo.push_back(k);
            }
        }
      
       
      
    }
      intialpop+=cnt;

    
vector<vector<vector<char>>> generations;
generations.push_back(arr);
    
    
    // copying the array for making the new generation
vector<vector<char>> copyarr(R,vector<char>(C));


vector<int> peak(G+1);
peak[0]=intialpop;
int period;
int firstrepeat;
int firstocc;
 string c;
 bool foundfirst=0;
 int stablestep;
 bool foundfirststable=0;
for(int m=1;m<=G;m++){
 for(int i = 0; i < R; i++) {
     for(int k = 0; k < C; k++) {
         copyarr[i][k] = arr[i][k];
     } }

    for(int i=0;i<R;i++){
        for(int k=0;k<C;k++){
            int cnt2=0;
            //checking the all 8 surrorudning for each block
            for(int t=-1;t<=1;t++){
                for(int s=-1;s<=1;s++){ if(t==0&&s==0) {}
                else {
                    //adding the toroidal mode
                    int newrow=((i+t+R)%R);
                    int newcol=((k+s+C)%C);
                   
                    if(arr[newrow][newcol]=='#'){cnt2++;}}
                }
            }
            //assigning new values into array;
            if(cnt2<2){copyarr[i][k]='.';}
            else if(arr[i][k]=='#'){
                if(cnt2==2||cnt2==3){}
                else{copyarr[i][k]='.';}

            }
            else{
                if(cnt2==3){copyarr[i][k]='#';}
            }

        }
    } 
    
    
    //assigning new generation into old one to keep updating
    for(int i=0;i<R;i++){
        for(int k=0;k<C;k++){
        arr[i][k]=copyarr[i][k];
        }
       
    
}
 generations.push_back(arr);

 for(int u=0;u<m;u++){

    bool oscilator=1;
    for(int i=0;i<R;i++){
        for(int k=0;k<C;k++){
            if (generations[u][i][k]!=generations[m][i][k]){
                oscilator=0;
                break;

            }
    }
    if(!oscilator) {break;}


 }
 if(oscilator==1){ if(!foundfirst){
    c="Oscillator";
    period=m-u;
    firstrepeat=m;
    firstocc=u;
    foundfirst=1;
    }
    break;
 }
}
// storing all the population values into a vector
int cnt3=0;
for(int i=0;i<R;i++){
        for(int k=0;k<C;k++){
       if (arr[i][k]=='#'){cnt3++;}
        }
    
}
peak[m]=cnt3;



}




// basically feature 1 toroidal wrapping
if(n == "toroidal"){
int finalpop=peak[G];
cout<<"Mode: "<<n<<endl;
cout<<"Initial Population: "<<intialpop<<endl;
cout<<"Final Population: "<<finalpop<<endl;

cout<<"Final Grid: "<<endl;
for(int i=0;i<R;i++){
        for(int k=0;k<C;k++){
            cout<<arr[i][k];
        }
        cout<<endl;
    }
}
// feature 2 to classify patterns
if(n=="classify"||n=="classifyk"){
   

   if( find(peak.begin(),peak.end(),0)!=peak.end()){
    c="Extinct";
   }
   
  
     if(c=="Extinct"){
   auto it= find(peak.begin(),peak.end(),0);
   int index=distance(peak.begin(),it);

   cout<<"classification: "<<c<<endl;
cout<<"Extinction Step: "<<index<<endl;
cout<<"Final Population: 0";}

 else if(c=="Oscillator"){
    if(period==1){
         cout<<"classification: "<<"Still Life"<<endl;
    cout<<"Stable at Step: "<<(firstocc)<<endl;
    cout<<"Period: 1"<<endl;
    cout<<"Final Population:"<<peak[firstocc];
    }
    else{
    cout<<"classification: "<<c<<endl;
    cout<<"Period: "<<period<<endl;
    cout<<"First Repeat Step: "<<firstrepeat<<"(matches step"<<firstocc<<")"<<endl;
cout<<"Population: "<<peak[firstrepeat];
    }
}
else{
    cout<<"Active"<<endl;
    cout<<"Reason: No repeat or extinction detected within K= "<< G <<" steps"<<endl;
    cout<<"Final Population: "<<peak[G];
}
}
//feature 3 to print all the metrics for the given input or pattern
if(n=="metrics"){
    if(cnt==0){
        cout<<"Live Cells: 0"<<endl<<"Bounding Box: 0 x 0"<<endl<<"Center of Mass: N/A";

    }
    else{
    sort(rcoo.begin(),rcoo.end());
    int rsize=rcoo.size();
    int csize=ccoo.size();
sort(ccoo.begin(),ccoo.end());
int H=rcoo[rsize-1]-rcoo[0]+1;
int W=ccoo[csize-1]-ccoo[0]+1;
cout<<"Live Cells:"<<peak[0]<<endl;
cout<<"Bounding Box:"<<H<<" x "<<W<<endl;
int rsum= accumulate(rcoo.begin(),rcoo.end(),0);
int csum= accumulate(ccoo.begin(),ccoo.end(),0);
double xcom = (double)rsum / peak[0];  
double ycom = (double)csum / peak[0];
cout << "Center of Mass: ("<< fixed << setprecision(2) << xcom << ", "<< ycom << ")";
    
    }
}


}

