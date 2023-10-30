//binary search normal
#include  <iostream>
using namespace std;
int bin_search(int arr[],int num,int low,int high)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]==num)
        {
            return mid;
        }
        else if (arr[mid]>num)
        {
            high=mid-1;
        }
        else if (arr[mid]<num)
        {
            low=mid+1;
        }
    }
    return -1;
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
    int found = bin_search(arr,num,0,size);
    if (found==-1)
    {
        cout<<"Element not found";
    }
    else
    {
        cout<<"Element found at position "<<found+1;
    }

}