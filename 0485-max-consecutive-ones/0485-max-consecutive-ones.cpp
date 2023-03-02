class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        int curr=0;
        
        for(auto it: nums)
        {
            if(it==1)
                curr++;
            else
            {
                res=max(curr,res);
                curr=0;
            }
        }
        res=max(curr,res);
        return res;
    }
};