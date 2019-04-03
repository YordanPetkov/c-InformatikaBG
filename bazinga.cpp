#include<iostream>
using namespace std;
int br[8],brA;
int main()
{
    string s;
    getline(cin,s);
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B' || s[i]=='b')br[0]++;
        if(s[i]=='A' || s[i]=='a')brA++;
        if(s[i]=='Z' || s[i]=='z')br[1]++;
        if(s[i]=='I' || s[i]=='i')br[2]++;
        if(s[i]=='N' || s[i]=='n')br[3]++;
        if(s[i]=='G' || s[i]=='g')br[4]++;
    }
    int min=brA/2;
    for(int i=0;i<5;i++)
    {
        if(br[i]<min)min=br[i];
    }
    cout<<min<<endl;
    return 0;
    
}