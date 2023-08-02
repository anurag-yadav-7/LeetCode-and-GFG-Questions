class Solution {
public:
    vector<vector<int>> res;
    
    void rec(vector<int> &temp, vector<int> &nums , vector<bool> &visited)
    {
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(!visited[i])
            {
                temp.push_back(nums[i]);
                visited[i] = true;
                rec(temp,nums,visited);
                visited[i] = false;
                temp.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
    
        int n = nums.size();
        vector<int> temp;
        vector<bool> visited(n,false);
        
        for(int i = 0 ; i<n ; i++)
        {
            temp.push_back(nums[i]);
            visited[i] = true;
            rec(temp,nums,visited);
            visited[i] = false;
            temp.pop_back();
        }
        
        return res;
    }
};