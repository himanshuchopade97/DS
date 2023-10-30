//lin search
#include <iostream>
using namespace std;
int lin_search(int arr[],int num,int size)
{
    for (int i=0;i<size;i++)
    {
        if (arr[i]==num)
        {
            return i+1;
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
    cout<<"Enter elements of array\n";
    for (int i=0;i<size;i++)
    {
        cout<<"Element "<<i+1<<" :";
        cin>>arr[i];
    }
    cout<<"Enter number to be searched :";
    cin>>num;
    int found=lin_search(arr,num,size);
    if (found==-1)
    {
        cout<<"Element not found ";
    }
    else
    {
        cout<<"Element found at position "<<found;
    }

}
