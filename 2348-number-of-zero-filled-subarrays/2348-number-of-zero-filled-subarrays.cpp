class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long res = 0 , count = 0;
        
        int n = nums.size();
        // bool prev_zero=false;
        
        
        for(int i = 0; i < n ; i++)
        {
            if(nums[i] != 0)
            {
                res += ((count)*(count+1))/2;
                // prev_zero = false;
                count = 0;
            }
            else if(nums[i] == 0)
            {
                // prev_zero = true;
                count++;
            }
        }
        
        if(count != 0)
        {
            res += ((count)*(count+1))/2;
        }
        
        return res;  
    }
};