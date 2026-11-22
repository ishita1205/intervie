#include<iostream>
#include <vector>

using namespace std;

vector<int> removeduplicates(vector<int> &arr)
{
    vector<int> result;
    int n=arr.size();
    if(n<=1)
    {
        return arr;
    }
    sort(arr.begin(),arr.end());
    result.push_back(arr[0]);

    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            result.push_back(arr[i]);
        
           
        }
    }


    return result;

    
    

}

int main()
{
    vector<int> arr={6,6,7,8,9,10,12,15,15,17};
    vector<int> res;
    res=removeduplicates(arr);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;
    }

    //O(N) time and O(1) space;
}