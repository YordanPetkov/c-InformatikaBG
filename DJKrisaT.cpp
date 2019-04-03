#include<iostream>
#define MAXN 100000
#define MAX_NODES 300000
#define MAX_VALUE 300000000
using namespace std;
struct Edge {
    int to,price,time;
};

vector <Edge> Bus[MAX_NODES];
vector <Edge> iterator :: I;
int N,M,K;
//long long Bus[MAXN][MAXN][2];//Bus[i][j][0] - price of line (i-j)
                             //Bus[i][j][1] - time of line (i-j)
bool IsPath(int a, int b){

    for(I = Bus.begin(); I < Bus.end(); I++){
        if(Bus[I])
    }
}

long long BusTime(int a, int b){

}

long long BusPrice(int a, int b){

}
long long dijkstra(int S){
    long long p[MAXN],t[MAXN];
    bool T[MAXN];
    for(int i = 0; i < N; i++){
        /*if(Bus[S][i][0] != 0){
            p[i] = Bus[S][i][0];
            t[i] = Bus[S][i][1];*/
            if(IsPath(S,i)){
                p[i] = Bus[S][i][0];
                t[i] = Bus[S][i][1];
            }
        }
        else {
            p[i] = MAX_VALUE;
            t[i] = MAX_VALUE;
        }
    }
    for(int i = 0; i < N; i++)
        T[i] = true;
    T[S] = false;

    while (true) {
        int MinJ,MinP = MAX_VALUE;
        for(int j = 0; j < N; j++){
            if(p[j] < MinP && T[j] == true && t[j] <= K){
                MinP = p[j];
                MinJ = j;
            }
        }
        if(MinP == MAX_VALUE)break;
        T[MinJ] = false;

        for(int i = 0; i < N; i++){
            /*if(Bus[i][MinJ][0] != 0 && T[i] == true){
                if(t[MinJ] + Bus[i][MinJ][1] <= K){
                    if(p[i] > p[MinJ] + Bus[i][MinJ][0]){
                        p[i] = p[MinJ] + Bus[i][MinJ][0];
                        t[i] = t[MinJ] + Bus[i][MinJ][1];
                    }
                }

            }
            */
            if(IsPath(i,MinJ) && T[i] == true){
                long long MyTime = BusTime(i,MinJ);
                long long MyPrice = BusPrice(i,MinJ);
                if(t[MinJ] + MyTime <= K){
                    if(p[i] > p[MinJ] + MyPrice){
                        p[i] = p[MinJ] + MyPrice;
                        t[i] = t[MinJ] + MyTime;
                    }
                }

            }
        }
    }
    return p[N-1];
}

int main() {
    cin>>N>>M>>K;
    for(int i = 0; i < M; i++){
        int A,B,P,T;
        cin>>A>>B>>P>>T;
        /*Bus[A][B][0] = P;
        Bus[B][A][0] = P;
        Bus[A][B][1] = T;
        Bus[B][A][1] = T;*/
        Edge CurEdge;
        CurEdge.to = B;
        CurEdge.price = P;
        CurEdge.time = T;
        Bus[A].push_back(CurEdge);
        CurEdge.to = A;
        Bus[B].push_back(CurEdge);
    }
    long long ans = dijkstra(0);
    if(ans == MAX_VALUE)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
