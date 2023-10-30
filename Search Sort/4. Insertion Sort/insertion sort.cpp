//insertion sort
#include <iostream>
using namespace std;
void insertion_sort(int arr[],int size)
{
    for (int i=1;i<size;i++)
    {
        int j=i-1;
        int current=arr[i];
        while (arr[j]>current && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;

    }
}
int main()
{
    int size;
    cout<<"Enter size of array :";
    cin>>size;
    int arr[size];
    cout<<"Enter elements of array\n";
    for (int i=0;i<size;i++)
    {
        cout<<"Element "<<i+1<<" :";
        cin>>arr[i];
    }
    cout<<"Array before sorting :";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    insertion_sort(arr,size);
    cout<<"\nArray after sorting :";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

}