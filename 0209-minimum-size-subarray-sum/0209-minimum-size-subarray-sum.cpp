class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        long long sum = nums[0];
        int low = 0, high = 0;
        int n = nums.size();
        int res = INT_MAX;
        
        while(low<=high && high < n )
        {
            if(sum<target)
            {
                high++;
                if(high<n)
                    sum += nums[high];
            }
            else
            {
                res = min(res,high-low+1);
                sum -= nums[low];
                low++;
            }
        }
        
        if(res == INT_MAX)
            return 0;
        return res;
        
    }
};