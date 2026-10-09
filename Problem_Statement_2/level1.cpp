#include<bits/stdc++.h>
using namespace std;
class bender
{
    public:
    string name;
    string element;
    int currenthp;
    int hp;
    int attack;
    int defense;
    int speed;
    vector<pair<string,int>> moves;


public:

bender(string name,string element,int hp,int attack,int defense,int speed,vector<pair<string,int>> moves){
    this->name=name;
this->element=element;
this->hp=hp;
this->currenthp=hp;
this->attack=attack;
this->defense=defense;
this->speed=speed;
this->moves=moves;


}

void display_stats(){
    cout<<name<<"(";
    cout<<element<<")- ";
    cout<<"HP: "<< currenthp<<"/"<<hp;
    cout<<" Attack: "<<attack;
    cout<<" Defense:"<<defense;
    cout<<" Speed:"<< speed<<endl;
    cout<<" Moves:";
    for(int i=0;i<4;i++){
        if(i==3){cout<<moves[i].first<<"("<<moves[i].second<<")";

        }
        else{
        cout<<moves[i].first<<"("<<moves[i].second<<"),";}

    }
}
void attacktarget(bender &defender,int movenum){
    cout<<name<<" used "<<moves[movenum].first<<endl;
    int damage = round((double)(attack * moves[movenum].second) / defender.defense);
cout<<defender.name<<" took "<<damage<<" damage ";
defender.currenthp-=damage;
if(defender.currenthp<0){
    defender.currenthp=0;
}
}


void checkfainted(){
    bool faint=0;
    if(currenthp==0){
        faint=1;
    }
    cout<<name<<" fainted ;"<<boolalpha<<faint;
}

};
int main(){
  bender kartik("kartik","fire",35,35,56,45,{{"Ember Slash", 40}, {"Quick Jab", 30}, {"Focus", 0}, {"Flame Surge", 70}});

kartik.display_stats();




 

}