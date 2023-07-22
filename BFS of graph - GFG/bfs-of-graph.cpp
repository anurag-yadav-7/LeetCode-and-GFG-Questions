//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here.
        
        queue<int> q;
        q.push(0);
        vector<int> visited(V,0);
        vector<int> res;
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i = 0 ; i<size ; i++)
            {
                int curr = q.front();
                q.pop();
                
                if(visited[curr] == 1)
                    continue;

                res.push_back(curr);
                visited[curr] = 1;
                
                for(int i = 0 ; i<adj[curr].size() ; i++)
                    q.push(adj[curr][i]);
                
            }            
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends