class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
                
        unordered_map<int,int> mp(numCourses);
        vector<vector<int>> graph(numCourses);
        vector<int> ans;
        int n = pre.size();
        
        for(int i = 0 ; i< n ; i++)
        {
            graph[pre[i][1]].push_back(pre[i][0]);
            mp[pre[i][0]]++;
        }
        
        int size = graph.size();

        queue<int> q;
        // cout<<"indegree: "<<endl;
        for(int i = 0 ; i < numCourses ; i++)
        {
            if(mp.find(i)==mp.end())
                q.push(i);
        }
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0 ; i<size ; i++)
            {   
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                
                for(int j = 0 ; j<graph[curr].size() ; j++)
                {
                    mp[graph[curr][j]]--;
                    if(mp[graph[curr][j]]==0)
                    {
                        // cout<<"pushed into queue: "<<graph[curr][j]<<endl;
                        q.push(graph[curr][j]);
                        mp.erase(graph[curr][j]);
                    }
                }
            }
                // cout<<endl;
        }
        
        if(mp.size() != 0)
            return {};
        
        return {ans};
    }
};