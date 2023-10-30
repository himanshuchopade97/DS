//lin search multiple
#include <iostream>
using namespace std;
int multiple_lin_search(int arr[],int num,int size)
{
    int count=0;
    for (int i=0;i<size;i++)
    {
        if (arr[i]==num)
        {
            cout<<"Element found at position "<<i+1<<endl;
            count++;
        }
    }
    return count;
}
int main()
{
    int size,num;
    cout<<"Enter the size of array :";
    cin>>size;
    int arr[size];
    cout<<"Enter elements of array\n";
    for (int i=0;i<size;i++)
    {
        cout<<"Element "<<i+1<<" :";
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched :";
    cin>>num;
    int count = multiple_lin_search(arr,num,size);
    cout<<"Element found "<<count<<" times";
}