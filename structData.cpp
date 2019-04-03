#include<iostream>
#include<vector>
#include<utility>
#include<map>
using namespace std;
int main()
{
    vector <int> a;
    int n;
    cin>>n;
    /*for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a.push_back(k);
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a.push_back(k);
    }
    for(int i=0;i<n*2;i++)
        cout<<a[i]<<" ";
    cout<<endl;
*/
    pair <string,int> k;
    k = make_pair("Gosho",18);
    k = make_pair("Ivan",13);
    cout<<k.first<<" "<<k.second<<endl;

    map<int> m;
    m["pesho"] = 3;
    cout<<m["pesho"]<<endl;

}
