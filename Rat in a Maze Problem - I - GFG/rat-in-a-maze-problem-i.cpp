//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    
    void rec(int i, int j, string &temp, vector<string> &res, vector<vector<int>> &m, int n, vector<vector<bool>> &visited)
    {
        if( i<0 || j<0 || i>=n || j>=n  || m[i][j] == 0 || visited[i][j])
            return;
            
        if(i == n-1 && j == n-1)
        {
            // cout<<"manzil: "<<temp<<endl;
            res.push_back(temp);
            return;
        }
        
        // cout<<"at i: "<<i<<" j: "<<j<<endl;   
        visited[i][j] = true;
        
        temp.push_back('D');
        rec(i+1, j, temp, res, m, n, visited );
        temp.pop_back();
        
        temp.push_back('L');
        rec(i,j-1, temp, res, m, n, visited );
        temp.pop_back();
        
        temp.push_back('R');
        rec(i,j+1, temp, res, m, n, visited );
        temp.pop_back();
        
        
        temp.push_back('U');
        rec(i-1,j, temp, res, m, n, visited );
        temp.pop_back();
        
        visited[i][j] = false;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        string temp = "";
        vector<string> res;
        
        rec(0, 0, temp, res, m, n, visited);
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends