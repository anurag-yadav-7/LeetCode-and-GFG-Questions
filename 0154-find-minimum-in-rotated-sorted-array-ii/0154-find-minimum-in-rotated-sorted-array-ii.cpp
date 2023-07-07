class Solution {
public:
    int findMin(vector<int>& nums) {
                
        int n = nums.size();
        int low = 0 , high = n-1;
        int mini = nums[n-1], mid ;
        // cout<<endl;
        while( low <= high )
        {
            mid = low + (high - low) / 2;
            // cout<<"low: "<<low<<" mid: "<<mid<<" high: "<<high<<endl;
            
            if(nums[mid] == nums[low] && nums[mid] == nums[high])
            {
                mini = min(mini,nums[mid]);
                low ++;
                high --;
            }
            else if(nums[mid] >= nums[low])
            {
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            else if(nums[mid] <= nums[high])
            {
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
        
        return mini;
        
        
    }
};