#include<iostream>

using namespace std;

void bubbleSort(int* array,int sizeOfArray)
{
    for(int i=1;i<=sizeOfArray;i++)
    {
        for(int j=0;j<sizeOfArray-1;j++)
        {
            if(array[j]>array[j+1])swap(array[j],array[j+1]);
        }
    }
}
void insertionSort(int* array,int sizeOfArray)
{
    for(int i=1;i<sizeOfArray;i++){
        for(int idx=i;idx>0 && array[idx]<array[idx-1];idx--)
        swap(array[idx],array[idx-1]);
    }
}

void gnomeSort(int* array,int sizeOfArray)
{
    for(int idx=1;idx<sizeOfArray;idx++)
    {
        if(idx>0 && array[idx]<array[idx-1])
        {
            swap(array[idx],array[idx-1]);
            idx-=2;
        }
    }
}

bool binarySearch(int* array,int sizeOfArray,int k)
{
    int left=0,right=sizeOfArray-1;

    while(left<=right)
    {
         int mid = (left+right)/2;
         if(k==array[mid])return true;
         if(k>array[mid])left=mid+1;
         if(k<array[mid])right=mid-1;
    }
    return false;
}
int main()
{
    int n;
    int a[20];
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    //bubbleSort(a,n);
    insertionSort(a,n);
    //gnomeSort(a,n);
    int k;
    cin>>k;
    if(binarySearch(a,n,k))cout<<"There is "<<k<<" in array :"<<endl;
    else cout<<"There is not "<<k<<" in array :"<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
