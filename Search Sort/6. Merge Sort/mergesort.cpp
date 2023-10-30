//merge sort
#include <iostream>
using namespace std;
void merge(int arr[],int l,int mid,int r)
{
    int n1=mid+1-l,n2=r-mid;
    int a[n1],b[n2];
    for (int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    for (int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=l;
    while (i<n1 && j<n2)
    {
        if (a[i]<=b[j])
        {
            arr[k]=a[i];
            k++;i++;
        }
        else
        {
            arr[k]=b[j];
            k++;j++;
        }
    }
    while (i<n1)
    {
        arr[k]=a[i];
        k++;i++;
    }
    while (j<n2)
    {
        arr[k]=b[j];
        k++;j++;
    }
}
void mergeSort(int arr[],int l,int r)
{
    if (l<r)
    {
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
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
    mergeSort(arr,0,size-1);
    cout<<"\nArray after sorting :";
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

}