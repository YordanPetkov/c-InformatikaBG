#include<iostream>
#define MAXN 1000
using namespace std;

long long Price[MAXN][MAXN];
int main(){
    int Seq[MAXN];

    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>Seq[i];
    }

    for(int left = n - 1; left >= 0; left--){
        for(int right = left; right < n; right++){
            int year = left + n - right;
            Price[left][right] =
            max (year * Seq[left] + (left < right ? Price[left+1][right] : 0),
                 year * Seq[right] + (left < right ? Price[left][right-1] : 0)

                 );
        }
    }
    cout<<Price[0][n-1]<<endl;
    return 0;
}
