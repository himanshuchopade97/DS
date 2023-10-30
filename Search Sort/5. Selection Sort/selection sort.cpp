//selection sort
#include <iostream>
using namespace std;
void sel_sort(int arr[],int size)
{
    for (int i=0;i<size-1;i++)
    {
        for (int j=i+1;j<size;j++)
        {
            if (arr[i]>arr[j])
            {
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;;
            }
        }
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
    sel_sort(arr,size);
    cout<<"\nArray after sorting :";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

}