class Solution {
public:
    
    int rec(int ind, vector<int> &nums, vector<int> &dp)
    {
        if(ind == 0)
            return 1;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int temp = 0,res = 1;
        for(int i = ind-1 ; i>=0 ; i--)
        {
            if(nums[i] < nums[ind])
            {
                temp = 1 + rec(i,nums,dp);
                res = max(res,temp);
            }
        }
        // cout<<"max least len from element "<<nums[ind]<<" "<<res<<endl;
        return dp[ind] = res;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        vector<int> dp(nums.size(),-1);
        for(int i = nums.size()-1 ; i>=0 ; i--)
            ans = max(ans,rec(i, nums,dp));
        return ans;
    }
};