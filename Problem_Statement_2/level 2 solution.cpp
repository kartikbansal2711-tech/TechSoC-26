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

void showstats(){
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


bool isfainted(){
    bool faint=0;
    if(currenthp==0){
        faint=1;
    }
    return faint;
}

};

class duel
{
    public:
    bender *bender1;
    bender *bender2;
    int turns;
    int crithits;
    int supereffhits;


public:

duel(bender &b1,bender &b2){
    this->bender1=&b1;
this->bender2=&b2;
this->turns=0;
this->crithits=0;
this->supereffhits=0;


}

double typemultiplier(string att,string def){
    double mult=1.0;
    if(att=="Water" && def=="Fire"){mult=2.0;}
    if(att=="Fire" && def=="Air"){mult=2.0;}
    if(att=="Air" && def=="Earth"){mult=2.0;}
    if(att=="Earth" && def=="Water"){mult=2.0;}

    if(att=="Fire" && def=="Water"){mult=0.5;}
    if(att=="Air" && def=="Fire"){mult=0.5;}
    if(att=="Earth" && def=="Air"){mult=0.5;}
    if(att=="Water" && def=="Earth"){mult=0.5;}
    return mult;
}

void doturn(bender &attacker,bender &defender,int movechoice=-1){
    if(movechoice<0 || movechoice>3){
        movechoice=rand()%4;
    }
    cout<<attacker.name<<" used "<<attacker.moves[movechoice].first<<"!"<<endl;

    double damage=(double)(attacker.attack * attacker.moves[movechoice].second) / defender.defense;

    double typemult=typemultiplier(attacker.element,defender.element);
    if(typemult==2.0){
        cout<<"Super Effective! ("<<attacker.element<<" is strong against "<<defender.element<<")"<<endl;
        supereffhits++;
    }
    if(typemult==0.5){
        cout<<"Not very effective... ("<<attacker.element<<" is weak against "<<defender.element<<")"<<endl;
    }

    double critmult=1.0;
    int r=rand()%100;
    if(r<10){
        cout<<"Critical Hit!"<<endl;
        crithits++;
        critmult=2.0;
    }

    damage=damage*typemult*critmult;
    int dmg=round(damage);
    if(dmg<1){
        dmg=1;
    }

    cout<<defender.name<<" took "<<dmg<<" damage!"<<endl;
    defender.currenthp-=dmg;
    if(defender.currenthp<0){
        defender.currenthp=0;
    }
    cout<<defender.name<<" HP: "<<defender.currenthp<<"/"<<defender.hp<<endl;
}

void startduel(){
    cout<<"=== DUEL BEGINS! ==="<<endl;
    cout<<bender1->name<<" ("<<bender1->element<<", HP: "<<bender1->currenthp<<"/"<<bender1->hp<<") VS ";
    cout<<bender2->name<<" ("<<bender2->element<<", HP: "<<bender2->currenthp<<"/"<<bender2->hp<<")"<<endl;
    cout<<endl;

    bender *first;
    bender *second;
    bool tie=0;
    if(bender1->speed > bender2->speed){
        first=bender1;
        second=bender2;
    }
    else if(bender2->speed > bender1->speed){
        first=bender2;
        second=bender1;
    }
    else{
        tie=1;
        if(rand()%2==0){
            first=bender1;
            second=bender2;
        }
        else{
            first=bender2;
            second=bender1;
        }
    }

    string winner="";
    while(winner==""){
        turns++;
        bender *attacker;
        bender *defender;
        if(turns%2==1){
            attacker=first;
            defender=second;
        }
        else{
            attacker=second;
            defender=first;
        }

        cout<<"Turn "<<turns<<": ";
        if(turns==1){
            if(tie){cout<<"Speed tie! ";}
            cout<<attacker->name<<" goes first! (Speed: "<<first->speed<<" vs "<<second->speed<<")"<<endl;
        }
        else if(turns%2==1){
            cout<<attacker->name<<" goes first!"<<endl;
        }
        else{
            cout<<attacker->name<<" strikes back!"<<endl;
        }

        doturn(*attacker,*defender);
        cout<<endl;

        if(defender->isfainted()){
            cout<<defender->name<<" fainted!"<<endl;
            cout<<"🏆 "<<attacker->name<<" wins the duel!"<<endl;
            winner=attacker->name;
        }
    }

    cout<<endl;
    cout<<"Duel Summary:"<<endl;
    cout<<"- Winner: "<<winner<<endl;
    cout<<"- Turns: "<<turns<<endl;
    cout<<"- Critical Hits: "<<crithits<<endl;
    cout<<"- Super Effective Hits: "<<supereffhits<<endl;
}

};

int main(){
    srand(time(0));

    bender kael("Kael", "Fire", 100, 58, 38, 88, {{"Ember Slash", 40}, {"Quick Jab", 30}, {"Focus", 0}, {"Flame Surge", 70}});
    bender mira("Mira", "Water", 92, 50, 45, 60, {{"Water Whip", 35}, {"Tide Push", 25}, {"Mist Veil", 0}, {"Tidal Wave", 60}});

    duel d(kael, mira);
    d.startduel();
}
