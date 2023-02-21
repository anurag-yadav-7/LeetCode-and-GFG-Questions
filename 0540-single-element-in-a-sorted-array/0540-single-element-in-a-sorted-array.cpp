class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int low=0,high=n-1;
        int mid;
        
        while(low<=high)
        {
            mid=(low+high)/2;
            
            if(mid%2==0)
            {
                if(mid+1<n && nums[mid+1]==nums[mid])
                    low=mid+2;
                else if(mid-1>=0 && nums[mid-1]==nums[mid])
                    high=mid-2;
                else
                    return nums[mid];
            }
            else
            {
                if(mid+1<n && nums[mid+1]==nums[mid])
                    high=mid-1;
                else if(mid-1>=0 && nums[mid-1]==nums[mid])
                    low=mid+1;
                else
                    return nums[mid];    
            }
        }
        return nums[low];
        
    }
};