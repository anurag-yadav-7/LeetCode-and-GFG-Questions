//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:    
    void rec(int vertex, vector<int> adj[], vector<int> &visited, vector<int> &res)
    {
        if(visited[vertex] == 1)
            return;
            
        res.push_back(vertex);
        visited[vertex] = 1;
        for(int i = 0 ; i<adj[vertex].size(); i++)
            rec(adj[vertex][i], adj, visited, res);
        return;
        
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<int> visited(V, 0);
        rec(0, adj, visited, res);
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends