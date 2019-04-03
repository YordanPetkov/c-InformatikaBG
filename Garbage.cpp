#include<iostream>
#define MAXN 100
using namespace std;
unsigned int dp[10000][10000];
unsigned short Box[100][100];
unsigned int n,m;
unsigned int Garbage_Smasher(unsigned int Begin, unsigned int End){
    unsigned int bx = Begin / m,by = Begin % m,ex = End / m,ey = End % m;
    if(dp[bx*m+by][ex*m+ey] == 18082000)return 0;
    if(dp[bx*m+by][ex*m+ey] != 0)return dp[bx*m+by][ex*m+ey];
    if(bx == ex){
        unsigned int MaxEnergy = 0;
        for(unsigned int i = by; i <= ey; i++){
            if(MaxEnergy < Box[bx][i])MaxEnergy = Box[bx][i];
        }
        if(MaxEnergy != 0)dp[bx*m+by][ex*m+ey] = MaxEnergy;
        else {dp[bx*m+by][ex*m+ey] = 18082000;return 0;}
        return dp[bx*m+by][ex*m+ey];
    }
    if(by == ey){
        unsigned int MaxEnergy = 0;
        for(unsigned int i = bx; i <= ex; i++){
            if(MaxEnergy < Box[i][by])MaxEnergy = Box[i][by];
        }
        if(MaxEnergy != 0)dp[bx*m+by][ex*m+ey] = MaxEnergy;
        else {dp[bx*m+by][ex*m+ey] = 18082000;return 0;}
        return dp[bx*m+by][ex*m+ey];
    }

    unsigned int top = Garbage_Smasher(bx*m + by,bx*m + ey) + Garbage_Smasher((bx+1)*m + by,ex*m + ey);
    unsigned int bottom = Garbage_Smasher(ex*m + by,ex*m + ey) + Garbage_Smasher(bx*m + by,(ex-1)*m + ey);
    unsigned int right = Garbage_Smasher(bx*m + ey,ex*m + ey) + Garbage_Smasher(bx*m + by,ex*m + ey-1);
    unsigned int left = Garbage_Smasher(bx*m + by,ex*m + by) + Garbage_Smasher(bx*m + by+1,ex*m + ey);
    dp[bx*m+by][ex*m+ey] = min(min(top,bottom),min(right,left));
    if(dp[bx*m+by][ex*m+ey] == 0){dp[bx*m+by][ex*m+ey]=18082000;return 0;}
    else return dp[bx*m+by][ex*m+ey];
}

int main()
{

    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>Box[i][j];
    cout<<Garbage_Smasher(0,n*m-1)<<endl;
    return 0;
}
