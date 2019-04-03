#include<iostream>
using namespace std;
#define MAXN 1000

int main()
{
    int Seq[MAXN];
    int Up[MAXN];
    int Down[MAXN];
    int MaxUp = 0;
    int MaxDown = 0;
    int MaxAns = 0;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>Seq[i];
    }

    Up[0] = 1;
    Down[0] = 1;
    for(int i = 1; i < n; i++){
        MaxUp = 0;
        MaxDown = 0;
        for(int j = 0; j < i; j++){
            if(Seq[i] > Seq[j]){
                if(MaxDown < Down[j])MaxDown = Down[j];
            }
            else if(Seq[i] < Seq[j]){
                if(MaxUp < Up[j])MaxUp = Up[j];
            }
        }
        Up[i] = MaxDown + 1;
        Down[i] = MaxUp + 1;
        if(Up[i] > MaxAns)MaxAns = Up[i];
        if(Down[i] > MaxAns)MaxAns = Down[i];
    }

    cout<<MaxAns<<endl;
    return 0;
}
