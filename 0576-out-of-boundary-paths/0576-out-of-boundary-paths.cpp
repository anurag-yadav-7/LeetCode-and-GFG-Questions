class Solution {
    #define mod 1000000007;
    
    int rec(int i, int j, int count, int m , int n ,vector<vector<vector<int>>> &dp)
    {
        if(i>=m || j>= n || i<0 || j<0)
            return 1;
        if(count == 0)
            return 0;
        
        if(dp[i][j][count] != -1)
            return dp[i][j][count];
        
        long long sum1 = rec(i-1 , j , count-1 , m , n , dp);
        long long sum2 = rec(i , j-1 , count-1 , m , n , dp);
        long long sum3 = rec(i+1 , j , count-1 , m , n , dp);
        long long sum4 = rec(i , j+1 , count-1 , m , n , dp);
        
        // cout<<" at index: "<<i<<","<<j<<" sum: "<<sum1+sum2+sum3+sum4<<endl;
        return dp[i][j][count] = ( sum1 + sum2 + sum3 + sum4 ) % mod;
         
    }
    
public:
    int findPaths(int m, int n, int k, int row, int col) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return (rec(row , col , k , m, n , dp))%mod;
        
    }
};

