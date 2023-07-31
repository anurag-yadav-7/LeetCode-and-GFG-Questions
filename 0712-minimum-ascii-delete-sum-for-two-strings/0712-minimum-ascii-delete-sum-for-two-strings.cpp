class Solution {
    int temp = 0;
    int rec(int i , int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(dp[i+1][j+1] != -1)
            return dp[i+1][j+1];
        if(i<0){
            if(j<0){
                return 0;
            }
            int index = j;
            temp = 0;
            while(j>=0){
                temp += s2[j];
                j--;
            }
            return dp[i+1][index+1] = temp;
        }
        if(j<0){
            int index = i;
            temp = 0;
            while(i>=0){
                temp += s1[i];
                i--;
            }
            return dp[index+1][j+1] = temp;
        }
        
        if(s1[i] == s2[j])
            return dp[i+1][j+1] = rec(i-1, j-1, s1, s2,dp);
        
        int first = s1[i] + rec(i-1, j, s1, s2 ,dp);
        int second = s2[j] + rec(i, j-1, s1, s2 ,dp);
        
        return dp[i+1][j+1] = min(first, second);
    }
    
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int len1 = s1.length();
        int len2 = s2.length();
        vector<vector<int>> dp(len1+1, vector<int> (len2+1,-1));
        return rec(len1-1, len2-1, s1, s2, dp );
    }
};