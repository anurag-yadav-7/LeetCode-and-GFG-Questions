class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int count = 0;
        unordered_map<int,int> mp;
        
        while(count<k)
        {
            mp[nums[count]]++;
            count++;
        }
        int n = nums.size();
        unsigned long long res = 0;
        unsigned long long tempsum=0;
        
        for(auto it: mp)
            tempsum += ((long long)(it.first)*(long long)(it.second));
        
        if(mp.size()==k)
            res = max(res,tempsum);
        // cout<<"in 1st window--> sum: "<<tempsum<<endl;
        for(int i=k ; i<n ; i++)
        {
            
            mp[nums[i-k]]--;
            
            tempsum -= nums[i-k];
            
            if(mp[nums[i-k]]==0)
                mp.erase(nums[i-k]);
            
            tempsum += nums[i];
            
            mp[nums[i]]++;
            
            if(mp.size()==k)
                res=max(res,tempsum);
            
            // cout<<"in "<<i<<"th window--> sum: "<<tempsum<<endl;
        }
        
        return res;
        
    }
};