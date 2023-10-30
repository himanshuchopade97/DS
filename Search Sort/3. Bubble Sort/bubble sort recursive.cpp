//bubble sort rec
#include<iostream>
using namespace std;
void rec_bubble_sort(int arr[],int size)
{
    if (size<=0)
        return;
    for (int i=0; i<size; i++)
    {
        if (arr[i]>arr[i+1])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    rec_bubble_sort(arr,size-1);
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
    rec_bubble_sort(arr,size);
    cout<<"\nArray after sorting :";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

}