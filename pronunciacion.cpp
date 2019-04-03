#include<iostream>
using namespace std;
int main()
{
    int n,br=0;
    bool word[100];
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        int k=s.size();
        for(int j=0;j<k;j++)
        {
            if(s[i]=='a' ||s[i]=='o' || s[i]=='u' ||s[i]=='e' ||s[i]=='i' )br++;
            else br--;
        }
        cout<<br<<endl;
        if(br>=0)word[i]=true;
        else word[i]=false;
        br=0;
    }
    for(int i=1;i<=n;i++){
    if(word[i])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    }
    return 0;
}
