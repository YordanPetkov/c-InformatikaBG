#include<iostream>
using namespace std;

int main()
{
    int n,brY=0,ans=0;
    bool flag = false;
    cin>>n;
    for(int i=1; i <= n; i++){
        char c;
        cin>>c;
        if(c=='N'){
            ans++;
            if(brY != 0)
            {
                ans += brY / 3;
                brY=0;
            }
        }
        else if(c=='Y' && i==2 && brY==1 && n==2){ans+=2;}
        else if(c=='Y' && i==2 && brY==0){ans++;}
        else if(c=='Y' && i==n && brY>=0){ans++;brY--;}
        else if(c=='Y'){
            brY++;
        }

    }
    ans += brY / 3;
    cout<<n-ans<<endl;
    return 0;
}
