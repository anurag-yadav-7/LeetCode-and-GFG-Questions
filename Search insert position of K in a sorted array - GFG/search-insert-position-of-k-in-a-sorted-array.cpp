//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>arr, int n, int x)
    {
        // code here
        if(x < arr[0])
            return 0;
        if(x > arr[n-1])
            return n;
        
        long long low = 0 , high = n-1;
        long long floor = -1;
        long long ceil = -1;
        
        while(low <= high)
        {
            long long mid = low + (high-low)/2;
            
            if(arr[mid] == x)
            {
                return mid;
            }
            
            if(arr[mid] < x)
            {
                floor = mid + 1; 
                low = mid + 1;
            }
                
            else if(arr[mid] > x)
                high = mid - 1;
        }
        
        return floor;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends