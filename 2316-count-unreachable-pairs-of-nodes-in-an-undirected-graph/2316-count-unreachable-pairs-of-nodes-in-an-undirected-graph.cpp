class Solution {
public:
    
    void dfs(int curr, vector<vector<int>> &adj , vector<bool> &visited , long long &count)
    {
        if(visited[curr])
            return;
        
        
        visited[curr] = true;
        
        count++;
        // cout<<"curr node: "<<curr<<" count value: "<<count<<endl;
        
        for(int i = 0 ; i<adj[curr].size(); i++)
        {
            if(!visited[adj[curr][i]])
                dfs(adj[curr][i], adj , visited , count);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int size =  edges.size();
        long long res = 0;
        
        for(int i = 0 ; i < size ; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
      
        vector<bool> visited (n+1,false);
        
        for(int i = 0 ; i<n ; i++)
        {
            long long count =  0;
            
            if(!visited[i])
            {
                dfs(i,adj,visited,count);    
                res += (count)*(n - count);
            }
        }
        
        
        return res/2;
        
    }
};