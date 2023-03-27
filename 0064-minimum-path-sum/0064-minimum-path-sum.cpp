class Solution {
    int sum=INT_MAX;
public:
    
    
//     void dfs(int i,int j, vector<vector<int>> &grid, vector<vector<bool>> &visited,int curr_sum, vector<vector<int>> &dp)
//     {
//         if(i>=grid.size() || j>=grid[0].size())
//             return;
//         if(visited[i][j])
//             return;
        
        
//         // cout<<"i: "<<i<<" j: "<<j<<endl;
//         curr_sum += grid[i][j];
        
//         if(i == grid.size()-1 && j == grid[0].size()-1)
//         {
//             sum = min(sum,curr_sum);
//         }
        
//         visited[i][j] = true;
        
//         dfs(i,j+1,grid,visited,curr_sum,dp);
        
//         dfs(i+1,j,grid,visited,curr_sum,dp);
        
//         visited[i][j] = false;
               
//         curr_sum -= grid[i][j];
//     }
    
    
   int helper(int i , int j, vector<vector<int>> &grid,vector<vector<int>> &dp)
   {
       if(i >= grid.size() || j>= grid[0].size())
           return 0;
       
       if (i == grid.size()-1 and j == grid[0].size()-1) return grid[i][j];
       
       if(dp[i][j] != -1)
            return dp[i][j];
       
       int down = 1e8;
       int right = 1e8;
       if(i<grid.size()-1)
            down = grid[i][j] + helper(i+1,j,grid,dp);
       
       if(j<grid[0].size()-1)
            right = grid[i][j] + helper(i,j+1,grid,dp);
       
       
       return dp[i][j]=min(down,right);
           
   }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        // vector<vector<bool>> visited(n,vector<bool> (m,false));
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        // dfs(0,0,grid,visited,0, dp);
        return helper(0,0, grid,dp);

    }
};