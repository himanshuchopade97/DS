//binary search recursive
#include <iostream>
using namespace std;
int rec_bin_search(int arr[],int num,int low,int high)
{
    int mid=(low+high)/2;
    if (arr[mid]==num)
        return mid;
    else if (arr[mid]<num)
        rec_bin_search(arr,num,mid+1,high);
    else if (arr[mid]>num)
        rec_bin_search(arr,num,low,mid-1);
    
}
int main()
{
    int size,num;
    cout<<"Enter size of array :";
    cin>>size;
    int arr[size];
    cout<<"Enter elements of array :";
    for (int i=0;i<size;i++)
    {
        cout<<"Element "<<i+1<<" :";
        cin>>arr[i];
    }
    cout<<"Enter element to be searched :";
    cin>>num;
    int found = rec_bin_search(arr,num,0,size);
    
        cout<<"Element found at position "<<found+1;
    

}