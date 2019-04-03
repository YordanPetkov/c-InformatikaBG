#include<iostream>
#include<utility>
#include<queue>
#include<vector>
using namespace std;
const int MAXN = 50;
vector<int> neighbour[MAXN];
int N,M;
bool used[MAXN];
void BFS(int x)
{
    for(int i=0;i<MAXN;i++)used[i]=false;
    used[x]=true;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        cout<<p<<" ";
        for(int i=0; i<neighbour[p].size(); i++)
        {
           if(used[neighbour[p][i]]==0) /* ако не е обходен */
           {
              q.push(neighbour[p][i]);
              used[neighbour[p][i]]=1;
           }
        }
    }
    cout<<endl;
}

void DFS(int x)
{
    used[x]=true;
    cout<<x<<" ";
    for(int i=0;i<neighbour[x].size();i++)
    {
        if(used[neighbour[x][i]]==false)
        {
            DFS(neighbour[x][i]);
        }
    }
    cout<<endl;
}

int main()
{
    int k;
    cin>>N>>M>>k;
    for(int i=0;i<M;i++)
    {
        int x,y;
        cin>>x>>y;
        neighbour[x].push_back(y);
        neighbour[y].push_back(x);
    }
    BFS(k);
    DFS(k);
    cout<<endl;
    return 0;
}
