class Solution {
    
void rec(int ind, int target,vector<int> &temp, vector<vector<int>> &st, vector<int> &candidates,bool flag)
    {

        if(target == 0)
        {
            st.push_back(temp);
            return;
        }
    
    
        for(int i = ind ; i<candidates.size() ; i++)
        {
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            
            if(candidates[i] > target) break;
            
            temp.push_back(candidates[i]);
            rec(i+1, target - candidates[i], temp, st, candidates,flag);
            temp.pop_back();
            // rec(ind+1, target, temp, st, candidates, flag);
                
        }
    
        
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        
        sort(arr.begin(), arr.end());
        set<vector<int>> st;
        vector<int> temp;
        vector<vector<int>> res;
        bool flag = false;
        rec(0, target, temp, res, arr, flag);
        
        // for(auto it: st)
        //     res.push_back(it);
        
        return res;
        
    }
};