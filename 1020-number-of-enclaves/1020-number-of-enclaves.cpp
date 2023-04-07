class Solution {
public:
    
    void dfs(vector<vector<int>>& board,int i,int j,vector<vector<int>>& visited)
    {
        
        if(i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1 || visited[i][j]==1)
            return;
    
        
        if(board[i][j]==0)
            return;
            
        
                visited[i][j]=1;
                dfs(board,i+1,j,visited);
                dfs(board,i,j-1,visited);
                dfs(board,i-1,j,visited);
                dfs(board,i,j+1,visited);
    }
    

    
    int numEnclaves(vector<vector<int>>& board) {
        
          
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        for(int i=0;i<board[0].size();i++)
        {
            if(board[0][i]==1)
                dfs(board,0,i,visited);
            if(board[m-1][i]==1)
                dfs(board,m-1,i,visited);
        }
        
        for(int i=0;i<board.size();i++)
        {
            if(board[i][0]==1)
                dfs(board,i,0,visited);
            if(board[i][n-1]==1)
                dfs(board,i,n-1,visited);
        }
        
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1 && visited[i][j]==0)
                    count++;
            }
        }

        return count;
    }
};