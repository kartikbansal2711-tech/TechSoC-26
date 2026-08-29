#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){

    int R,C,G;
    cin>>R>>C>>G;
    int intialpop=0;
   vector<vector<char>> arr(R,vector<char>(C));
   

    //counting the initial population and assigning values in 2d array
    for(int i=0;i<R;i++){
        string s;
        
        cin>>s;
        if(s.size()>C){}
        for(int k=0;k<C;k++){
            arr[i][k]=s[k];
        }
       int  cnt=0;
        for(int m=0;m<C;m++){
            
            if(s[m]=='#'){
                cnt++;
            }
        }
        intialpop+=cnt;
    }

    
    
    // copying the array for making the new generation
vector<vector<char>> copyarr(R,vector<char>(C));
bool stilllife=1;
vector<int> peak(G+1);
peak[0]=intialpop;
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
                for(int s=-1;s<=1;s++){
                    if(i+t<0||k+s<0||i+t>=R||k+s>=C||((t|s)==0)){}
                    else{
                    if(arr[i+t][k+s]=='#'){cnt2++;}}
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
// storing all the population values into a vector
int cnt3=0;
for(int i=0;i<R;i++){
        for(int k=0;k<C;k++){
       if (arr[i][k]=='#'){cnt3++;}
        }
    
}
peak[m]=cnt3;

//printing the final generation



}
int finalpop=peak[G];
cout<<"Initial Population:"<<intialpop<<endl;
cout<<"Final Population:"<<finalpop<<endl;
sort(peak.begin(),peak.end());
int peakpop=peak[G];
cout<<"Peak Population:"<<peakpop<<endl;
cout<<"Final Grid:"<<endl;
for(int i=0;i<R;i++){
        for(int k=0;k<C;k++){
            cout<<arr[i][k];
        }
        cout<<endl;
    }
}