class Solution {
    vector<vector<int>> res;
    void rec(int ind, vector<int> &curr, int n, int k, vector<bool> &visited)
    {
        if(curr.size() == k)
        {
            res.push_back(curr);
            return;
        }
        
        for(int i = ind+1; i<=n ; i++)
        {
            if(visited[i]) continue;
            curr.push_back(i);
            visited[i] = true;
            rec(i, curr, n, k, visited);
            curr.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<bool> visited(n+1,false);
        vector<int> curr;
        for(int i = 1 ; i<=n ; i++)
            {
                curr.push_back(i);
                visited[i] = true;
                rec(i, curr, n, k, visited);
                curr.pop_back();
                visited[i] = false;
            }
        return res;
    }
};