#include<iostream>
#define MAXN 100000
using namespace std;

int main()
{
    int n;
    long long Ribbons[MAXN];
    char Colors[MAXN];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>Colors[i];
    }
    Ribbons[n-1] = 0;
    Ribbons[n-2] = (Colors[n-2] == Colors[n-1] ? 1 : 0);

    if(Colors[n-3] != Colors[n-2] && Colors[n-3] != Colors[n-1] && Colors[n-2] != Colors[n-1]){cout<<-1<<endl;return 0;}
    else Ribbons[n-3] = 1;

    for(int i = n - 4; i >= 0; i--){
        if(((Colors[i] != Colors[i+1] && Colors[i] == Colors[i+2])
           || (Colors[i] != Colors[i+1] && Colors[i] != Colors[i+2] && Colors[i+1] == Colors[i+2])) ){//RGR && RGG
            if(Ribbons[i+3] != 0)Ribbons[i] = Ribbons[i+3] + 1;
            else Ribbons[i] = 0;
        }
        else if(Colors[i] != Colors[i+1] && Colors[i] != Colors[i+2]
                && Colors[i+1] != Colors[i+2]){ // RGB
            if(Ribbons[i+1] == 0 && Ribbons[i+2] == 0){
                cout<<-1<<endl;return 0;
            }
            else Ribbons[i] = 0;
        }
        else if(Ribbons[i+2] == 0 && Ribbons[i+3] == 0){
                cout<<-1<<endl;return 0;
            }
        else { //RRR RRG
            ///if(Ribbons[i+3] == 0)
            Ribbons[i] = max(Ribbons[i+2], Ribbons[i+3]) + 1;
        }
    }
    /*
    for(int i = 0; i < n; i++)
        cout<<i<<": "<<Ribbons[i]<<" "<<endl;
        */
    if(Ribbons[0] != 0)cout<<Ribbons[0]<<endl;
    else cout<<-1<<endl;
    return 0;
}


