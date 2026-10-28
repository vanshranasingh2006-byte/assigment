#include<bits/stdc++.h>
using namespace std;

void selectionsort(int[],int);
void insertionsort(int[],int);

int main()
{
    int n;
    cout<<"Enter the number of element u want to insert : ";
    cin >>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<" Element: ";
        cin>>arr[i];
    }

    cout<<"Before sort: ";
    for(int i=0;i<n;i++)
    {
       cout<<arr[i]<<" ";
    }

    insertionsort(arr,n);

    cout<<"\nAfter sort: ";
    for(int i=0;i<n;i++)
    {
       cout<<arr[i]<<" ";
    }


}

void selectionsort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min_indx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min_indx]>arr[j])
            {
                min_indx=j;
            }
        }

        //swap(arr[i],arr[min_indx]);
        int temp = arr[i];
        arr[i]=arr[min_indx];
        arr[min_indx]=temp;
    }
}

void insertionsort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i-1;
        int temp=arr[i];
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}