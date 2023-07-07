class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        
        int n = nums.size();
        int low = 0 , high = n-1, mid;
        
        while(low <= high)
        {
            mid = low + (high - low)/2;
            
            if(nums[mid] == target)
                return true;
            
            if(nums[low] <= nums[mid] && nums[high] >=nums[mid])
            {
                if(nums[low] == nums[mid] && nums[high] == nums[mid])
                {
                    low ++;
                    high --;
                }
                else if(nums[mid] < target )
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            
            else if(nums[low] <= nums[mid])
            {
                if(nums[low] <= target && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if(nums[high] >= nums[mid])
            {
                if(nums[high] >= target && target >= nums[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};