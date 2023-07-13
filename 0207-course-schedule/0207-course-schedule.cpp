class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        unordered_map<int,int> mp(numCourses);
        vector<vector<int>> graph(numCourses);

        int n = pre.size();
        
        for(int i = 0 ; i< n ; i++)
        {
            graph[pre[i][1]].push_back(pre[i][0]);
            mp[pre[i][0]]++;
        }
        
        int size = graph.size();
        // for(int i = 0 ; i< size ; i++)
        // {
        //     cout<<i<<": ";
        //     for(int j = 0 ; j<graph[i].size(); j++)
        //         cout<<graph[i][j]<<" ";
        //     cout<<endl;
        // }
        
        
        // cout<<"Inorder: "<<endl;
        
        queue<int> q;
        // cout<<"indegree: "<<endl;
        for(int i = 0 ; i < numCourses ; i++)
        {
            if(mp.find(i)==mp.end())
            {
                // cout<<i<<": "<<0<<endl;
                q.push(i);
            }
            // else
            //     cout<<i<<": "<<mp[i]<<endl;
        }
        // cout<<endl;
        
        while(!q.empty())
        {
            // cout<<"current queue: ";
            int size = q.size();
            for(int i = 0 ; i<size ; i++)
            {   
                int curr = q.front();
                q.pop();
                // cout<<curr<<" "; 
                for(int j = 0 ; j<graph[curr].size() ; j++)
                {
                    // cout<<graph[curr][j]<<" ";
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
        
        if(mp.size()!=0)
            return false;
        return true;
    }
};