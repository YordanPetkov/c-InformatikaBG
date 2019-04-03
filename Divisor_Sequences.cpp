#include<iostream>
#include<cmath>
using namespace std;

int n,k;
long long Counter[1024][1024];
long long Count_Permutations(int num, int pos){
    if(pos == n-1){Counter[num][pos] = 1;return 1;}
    if(Counter[num][pos] != 0)return Counter[num][pos];

    int SqrtN = sqrt(num);
    long long Answer = 0;
    for(int i = 1; i <= SqrtN; i++){//Divisors
        if(num % i == 0)Answer += Count_Permutations(i, pos+1);
    }
    int Cur_Num = num;
    if(num == 1)Cur_Num++;
    for(int i = num; i <= k; i++){
        if(i % num ==0 && i != 1)Answer += Count_Permutations(i, pos+1);
    }
    Counter[num][pos] = Answer;
    return Answer;
}

int main()
{


    long long ans=0;
    cin>>n>>k;
    for(int i = 1; i <= k; i++){
        ans += Count_Permutations(i,0);
    }
    /*for(int i = 1; i <= k; i++)
        for(int j = 0; j < n; j++)
            cout<<Counter[i][j]<<endl;*/
    cout<<ans % 1000000007<<endl;
    return 0;
}
