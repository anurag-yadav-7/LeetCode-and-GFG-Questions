class Solution {
    
    
    void rec(int ind, vector<int> &nums, string &ans, vector<bool> &visited, int n, int &k)
    {
        
        if(ans.length() == n)
        {
            k--;
            return;
        }
        
        for(int i = 0 ; i<n ; i++)
        {
            if(visited[i]==false)
            {
                ans.push_back(nums[i] + 48);
                visited[i] = true;
                rec(i, nums, ans, visited, n,k);
                if(k == 0)
                    return;
                visited[i] = false;
                ans.pop_back();
            }
        }
        
        
    }

public:
    string getPermutation(int n, int k) {
        
        vector<int> nums;
        for(int i = 1 ; i<=n ; i++)
            nums.push_back(i);
        
        vector<bool> visited(n,false);
        string ans = "";
        rec(0, nums,ans, visited, n, k);

        return ans;
    }
};