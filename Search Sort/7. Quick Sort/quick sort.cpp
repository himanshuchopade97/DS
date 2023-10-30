//quick sort
#include <iostream>
using namespace std;
void swap (int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partition(int arr[],int l,int r)
{
    int pivot=r;
    int i=l;
    int j=r;
    while (i<j)
    {
        while (arr[i]<arr[pivot])
        {
            i++;
        }
        while (arr[j]>arr[pivot])
        {
            j--;
        }
        if (i<j)
        {
            swap(arr,i,j);
        }
    }
    swap(arr,pivot,j);
    return j;
}
void quickSort(int arr[],int l,int r)
{
    if (l<r)
    {
        int pi = partition(arr,l,r);

        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
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
    quickSort(arr,0,size-1);
    cout<<"\nArray after sorting :";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

}