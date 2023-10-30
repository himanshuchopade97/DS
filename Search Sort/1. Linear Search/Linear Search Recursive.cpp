//linear search rec
#include <iostream>
using namespace std;
int rec_lin_search(int arr[],int num,int index)
{
    if (arr[index]==num)
    {
        return index+1;
    }
    else
    {
        rec_lin_search(arr,num,index+1);
    }
    
}
int main()
{
    int size,num;
    cout<<"Enter size of array :";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array\n";
    for (int i=0;i<size;i++)
    {
        cout<<"Element "<<i+1<<" :";
        cin>>arr[i];
    }
    cout<<"Enter element to be searched :";
    cin>>num;
    int found = rec_lin_search(arr,num,0);
    if (found)
    {
        cout<<"Element found at position "<<found;
    }   
    else
    {
        cout<<"Element not found ";
    }
}