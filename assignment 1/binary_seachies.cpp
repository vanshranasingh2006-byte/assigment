#include<bits/stdc++.h>
using namespace std;

int Ceil(int arr[],int n,int target)
{
    int low=0;
    int high=n-1;
    int ans_ind=-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==target)
        {
            ans_ind=mid;
            return ans_ind;
        }
        else if(arr[mid]>target)
        {
            ans_ind=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    } 
    return ans_ind;  
}

int main()
{
    int arr[]={1,3,5,7,9,11};
    int target;
    cout<<"enter target : ";
    cin>>target;
    int indx=Ceil(arr,6,target);
    cout<<arr[indx];

}