class Solution {
    int rec(int n1, int n2, string &s1, string &s2, vector<vector<int>> &dp){
        
        if(dp[n1+1][n2+1] != -1) return dp[n1+1][n2+1];

        if(n1<0 || n2<0){
            int temp = 0;
            if(n1<0 && n2>=0){
                int index = n2;
                while(n2>=0){
                    temp += s2[n2];
                    n2--;
                }
                // cout<<"pehla if"<<endl;
                return dp[n1+1][index+1] = temp;
            }
            else if(n2<0 && n1>=0){
                int index = n1;
                while(n1>=0){
                    temp += s1[n1];
                    n1--;
                }
                // cout<<"dusra if"<<endl;
                return dp[index+1][n2+1] = temp;
            }
            else
            {
                // cout<<"last if 0 wala"<<endl;
                return 0;
            }
        }
        if(s1[n1] == s2[n2]) 
            return dp[n1+1][n2+1] = rec(n1-1,n2-1,s1,s2,dp);
        return dp[n1+1][n2+1] = min((s1[n1]+rec(n1-1,n2,s1,s2,dp)),(s2[n2]+rec(n1,n2-1,s1,s2,dp)));
    }
    
    public:

    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return rec(n1-1,n2-1,s1,s2,dp);
    }
};