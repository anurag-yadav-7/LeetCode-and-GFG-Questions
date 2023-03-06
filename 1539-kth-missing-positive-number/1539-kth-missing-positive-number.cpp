class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int ans[2002]={0};
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            ans[arr[i]]++;
            // cout<<"freq of "<< i<<": "<<ans[i]<<endl;
        }
        
        int count=0;
        for(int i=1;i<2002;i++)
        {
            if(ans[i]==0)
            {
                // cout<<"missing no: "<<i<<endl;
                count++;
            }
            if(count==k)
                return i;
        }
        
        // cout<<"ans: "<<count<<endl;
        return 0;
    }
};