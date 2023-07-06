class Solution {
    
    
    void rec(int ind, vector<int> &nums, vector<int> &temp, vector<bool> &visited, int n, vector<int> &res, int &k)
    {
        
        if(temp.size() == n)
        {
            k--;
            return;
        }
        
        for(int i = 0 ; i<n ; i++)
        {
            if(visited[i]==false)
            {
                temp.push_back(nums[i]);
                visited[i] = true;
                rec(i, nums, temp, visited, n, res,k);
                if(k == 0)
                    return;
                visited[i] = false;
                temp.pop_back();
            }
        }
        
        
    }

public:
    string getPermutation(int n, int k) {
        
        vector<int> nums;
        for(int i = 1 ; i<=n ; i++)
            nums.push_back(i);
        
        vector<bool> visited(n,false);
        vector<int> res;
        vector<int> temp;
        rec(0, nums,temp, visited, n, res,k);

        string ans = "";
        for(auto it: temp)
            ans += (char)(it+48); 
        
        return ans;
    }
};