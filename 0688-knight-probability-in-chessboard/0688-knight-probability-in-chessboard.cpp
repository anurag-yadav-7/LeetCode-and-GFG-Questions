class Solution {

    double rec(int i, int j, int count, int n,vector<vector<vector<double>>> &dp)
    {
        if(i>=n || j>=n || i<0 || j<0)
            return 0;
        if(count == 0)
            return 1;
        
        if(dp[i][j][count] != -1)
            return dp[i][j][count];
        
        double sum1 = rec(i-1 , j-2 , count-1 , n , dp);
        double sum2 = rec(i+1 , j-2 , count-1 , n , dp);
        double sum3 = rec(i-2 , j-1 , count-1 , n , dp);
        double sum4 = rec(i-2 , j+1 , count-1 , n , dp);
        double sum5 = rec(i-1 , j+2 , count-1 , n , dp);
        double sum6 = rec(i+1 , j+2 , count-1 , n , dp);
        double sum7 = rec(i+2 , j-1 , count-1 , n , dp);
        double sum8 = rec(i+2 , j+1 , count-1 , n , dp);
        
        return dp[i][j][count] = sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8;
         
    }
    
    
public:
    double knightProbability(int n, int k, int row, int column) {
        
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        double actualpossi = rec(row , column , k , n , dp);
        double totalpossi = pow(8,k);
        cout<<"totalpossi: "<<totalpossi<<" actual: "<<actualpossi<<endl;
        return actualpossi/((1.0)*(totalpossi));
    }
};