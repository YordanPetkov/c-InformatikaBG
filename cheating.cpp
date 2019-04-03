#include<iostream>
#include<algorithm>
#include <stdio.h>
#include<cmath>
#define MAX_VALUE 30000
#define NO_PARENT -1
#define MAX_N 10000
using namespace std;
int d[MAX_N],n,m,k;
bool T[MAX_N];
int Table[MAX_N][MAX_N];
vector <int> V[MAX_N];
int djikstra(int Eli){
    /*for(int i = 0; i < n; i++){
        if(Table[Eli][i] != 0)d[i] = Table[Eli][i]-1;
        else d[i] = MAX_VALUE;
        T[i] = 1;
    }*/

    for(int i = 0; i < n; i++)d[i]=MAX_VALUE;
    for(int i = 0; i < V[Eli].size(); i++){
        d[i] = V[Eli].at(i);
        T[i] = 1;
    }
    T[Eli] = 0;

    while(true){
        int di = MAX_VALUE,j=NO_PARENT;
        for(int i = 0; i < n; i++){
            if(d[i] < di && T[i] == true){di = d[i]; j = i;}
        }
        if(j == NO_PARENT)break;
        T[j] = false;

        /*for(int i = 0; i < n; i++){
            if(Table[j][i] != 0 && T[i] == true && d[i] > d[j] + Table[j][i]-1)d[i] = d[j] + Table[j][i]-1;
        }*/
        for(int i = 0; i < V[j].size(); i++){
            if(V[j].at(i) != 0 && T[i] == true && d[i] > d[j] + V[j].at(i))d[i] = d[j] + V[j].at(i);
        }
    }

    if(d[n-1] == MAX_VALUE)return -1;
    return d[n-1];
}

int main()
{

    cin>>n>>m>>k;
    for(int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        Table[x][y] = 1;
        Table[y][x] = 1;
        V[x].push_back(0);
        V[y].push_back(x);
    }
    for(int i = 0; i < k; i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        Table[x][y] = 2;
        Table[y][x] = 2;
        V[x].push_back(y+1);
        V[y].push_back(x+1);
    }

    cout<<djikstra(0)<<endl;

    return 0;

}
