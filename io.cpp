#include<iostream>
using namespace std;
int main()
{
    string Type,aa;
    long long a[101];
    cin>>Type;
    if(Type=="String")
    {
        cin>>aa;
        int n=aa.size();
        for(int i=n-1;i>=0;i--)
        cout<<aa[i];
        cout<<endl;
    }
    else
    {
        int i=0;
        while(cin)
        {
            cin>>a[i];
            i++;
        }
        for(int j=i-2;j>=0;j--)
        cout<<a[j]<<" ";
        cout<<endl;
    }
    return 0;
}