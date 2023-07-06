class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        long long sum = nums[0];
        int low = 0, high = 0;
        int n = nums.size();
        int res = INT_MAX;
        
        while(low<=high && high < n )
        {
            // cout<<"curr low: "<<nums[low]<<" high: "<<nums[high]<<" sum: "<<sum<<endl;
            if(sum >= target)
            {
                res = min(res,high-low+1);
            }
            
            
            
            if(sum<target)
            {
                high++;
                if(high<n)
                    sum += nums[high];
            }
            else
            {
                sum -= nums[low];
                low++;
            }
        }
        
        if(res == INT_MAX)
            return 0;
        return res;
        
    }
};