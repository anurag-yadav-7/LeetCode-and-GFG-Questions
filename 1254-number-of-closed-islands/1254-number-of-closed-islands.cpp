class Solution {
bool flag = true;
public:
    
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, int m ,int n)
    {
        // cout<<"dfs i: "<<i<<" j: "<<j<<endl;
        
        if(i<0 || j<0 || i==m || j==n)
        {
            // cout<<"boundary condition found, hence returned"<<endl;
            return;
        }
        if(grid[i][j]==1 || visited[i][j]==true)
        {
            // cout<<"value==1 || already visited, hence returned"<<endl;
            return;
        }
        visited[i][j] = true;
        
        
        
        if(i-1<0 || j-1<0 || i+1>=m || j+1>=n )
        {
            flag = false;
        }
        
        dfs(i-1,j,grid,visited,m,n);
        dfs(i,j+1,grid,visited,m,n);
        dfs(i,j-1,grid,visited,m,n);
        dfs(i+1,j,grid,visited,m,n);
        // cout<<"all 4 calls over"<<endl;
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        int count=0;
        
        // cout<<"at index--> i: 0 j: 0"<<endl;
        // for(auto it: visited)
        // {
        //     for(auto itr: it)
        //         cout<<itr<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        
        for(int i=0; i<m ; i++)
        {
            for(int j =0; j<n ; j++)
            {
                flag= true;
                if(!visited[i][j] && grid[i][j]==0)
                {
                    dfs(i,j,grid,visited,m,n);
                    
                    // cout<<"at index--> i: "<<i<<" j: "<<j<<endl;
                    // for(auto it: visited)
                    // {
                    //     for(auto itr: it)
                    //         cout<<itr<<" ";
                    //     cout<<endl;
                    // }
                    // cout<<endl;
                    
                    if(flag)
                        count++;
                }
            }
        }
        return count;
    }
};