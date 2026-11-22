#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int low, int mid, int high)
{
    vector<int> temp;

    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }

    }

    while(left<=mid)
    {
        temp.push_back(arr[left]);
    }

    while(right<=high)
    {
        temp.push_back(arr[right]);
    }

    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];

    }


}

void mergesort(vector<int> &arr,int left, int right)
{
    if(left>=right)
    {
        return;
    }

    int mid=left+(right-left)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);


}

int main()
{
    vector<int> arr={76,34,87,22,90};
    int n=arr.size();

    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }

    return 0;
}
