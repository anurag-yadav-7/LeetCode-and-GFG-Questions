class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int n = nums.size();
        
        int negative = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(nums[i]==0)
                return 0;
            if(nums[i]<0) negative++;
        }
        if(negative%2 == 1)
            return -1;
        return 1;
        
    }
};