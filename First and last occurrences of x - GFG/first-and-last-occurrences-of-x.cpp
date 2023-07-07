//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    
    int low = 0, high = n-1;
    int mid, first = -1, last = -1;
    
    
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        
        if(arr[mid] >= x)
        {
            if(arr[mid] == x)
                first = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    low = 0, high = n - 1 ;
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        
        if(arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            if(arr[mid] == x)
                last = mid;
            low = mid + 1;
        }
    }
    return {first, last};
    
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends