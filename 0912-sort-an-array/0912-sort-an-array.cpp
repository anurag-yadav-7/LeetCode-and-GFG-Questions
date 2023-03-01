class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>, greater<int>> pq;
        
        for(auto it: nums)
            pq.push(it);
        
        vector<int> res;
        
        while(!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        
        // reverse(res.begin(),res.end());
        
        return res;
    }
};