class Solution {
    
    set<vector<int>> res;
    vector<int> temp;
    
public:
    
    void rec(int ind,vector<int> &nums)
    {
        // cout<<"ind: "<<ind<<endl;
        if(ind==nums.size())
        {
            // cout<<"Base case..."<<endl;
            if(temp.size()>1)
            res.insert(temp);
            return;
        }
     
        if(nums[ind]>=temp.back())
            {
                // cout<<"greater than top... "<<endl;
                temp.push_back(nums[ind]);
                rec(ind+1,nums);
                temp.pop_back();
                rec(ind+1,nums);
            }
            else
            {
                // cout<<"case2: not greater than top..."<<endl;
                rec(ind+1,nums);
            }
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {
            // cout<<"Starting from: "<<nums[i]<<endl;
            temp.push_back(nums[i]);    
            rec(i+1,nums);
            temp.pop_back();
        }
        vector<vector<int>> ans;
        for(auto it: res)
            ans.push_back(it);
        return ans;
        
    }
};