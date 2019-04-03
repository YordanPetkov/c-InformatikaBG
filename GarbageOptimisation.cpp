#include<iostream>
#include<vector>
#define MAXN 100
using namespace std;
struct  DoubleArray{
    vector <unsigned int> E;
}dp[10000];
vector <unsigned int> :: iterator Vi;
unsigned short Box[100][100];
unsigned int n,m;
unsigned int Garbage_Smasher(unsigned int Begin, unsigned int End){
    Vi = dp[Begin].E.begin();
    unsigned int bx = Begin / m,by = Begin % m,ex = End / m,ey = End % m;
    if(dp[Begin].E[End-Begin] == 18082000)return 0;
    if(dp[Begin].E[End-Begin] != 0)return dp[Begin].E[End-Begin];
    //cout<<Begin<<" "<<End<<endl;
    if(bx == ex && by == ey){
        unsigned int MaxEnergy = Box[bx][by];

        if(MaxEnergy != 0)dp[Begin].E.insert(Vi+End-Begin,MaxEnergy);
        else {dp[Begin].E.insert(Vi+End-Begin,18082000) ;return 0;}
        return dp[Begin].E[End-Begin];
    }
    if(bx == ex){
        unsigned int MaxEnergy = 0;
        for(unsigned int i = by; i <= ey; i++){
            if(MaxEnergy < Box[bx][i])MaxEnergy = Box[bx][i];
        }
        if(MaxEnergy != 0)dp[Begin].E.insert(Vi+End-Begin,MaxEnergy);
        else {dp[Begin].E.insert(Vi+End-Begin,18082000) ;return 0;}
        return dp[Begin].E[End-Begin];
    }
    if(by == ey){
        unsigned int MaxEnergy = 0;
        for(unsigned int i = bx; i <= ex; i++){
            if(MaxEnergy < Box[i][by])MaxEnergy = Box[i][by];
        }
        if(MaxEnergy != 0)dp[Begin].E.insert(Vi+End-Begin,MaxEnergy) ;
        else {dp[Begin].E.insert(Vi+End-Begin,18082000);return 0;}
        return dp[Begin].E[End-Begin];
    }

    unsigned int top = Garbage_Smasher(bx*m + by,bx*m + ey) + Garbage_Smasher((bx+1)*m + by,ex*m + ey);
    unsigned int bottom = Garbage_Smasher(ex*m + by,ex*m + ey) + Garbage_Smasher(bx*m + by,(ex-1)*m + ey);
    unsigned int right = Garbage_Smasher(bx*m + ey,ex*m + ey) + Garbage_Smasher(bx*m + by,ex*m + ey-1);
    unsigned int left = Garbage_Smasher(bx*m + by,ex*m + by) + Garbage_Smasher(bx*m + by+1,ex*m + ey);
    dp[Begin].E.insert(Vi+End-Begin,min(min(top,bottom),min(right,left)));
    if(dp[Begin].E[End-Begin] == 0){dp[Begin].E[End-Begin]=18082000;return 0;}
    else return dp[Begin].E[End-Begin];
}

int main()
{

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        dp[i].E.resize(n*m-i);
        for(int j = 0; j < m; j++)
            cin>>Box[i][j];
    }


    cout<<Garbage_Smasher(0,n*m-1)<<endl;
    for(int i = 0; i < n*m; i++){
        for(Vi = dp[i].E.begin(); Vi < dp[i].E.end(); Vi++){
            cout<<dp[i].E[Vi-dp[i].E.begin()]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
