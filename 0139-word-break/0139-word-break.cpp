class Solution {
    
    bool rec(int ind, string temp, string &s, unordered_set<string> &mp,
        map<int,map<string,int>> &dp)
    {
        if(dp[ind][temp] != 0)
            return dp[ind][temp] == 1;
        
        if(ind == s.length())
        {
            // cout<<"base case -> at ind: "<<ind<<" temp: "<<temp<<endl;
            bool first = temp =="" || mp.find(temp)!=mp.end();
            if(first)
                dp[ind][temp] = 1;
            else
                dp[ind][temp] = -1;
            return first;
        }
        
        if(mp.find(temp)!=mp.end())
        {
            // cout<<"word found ---> at ind: "<<ind<<" temp: "<<temp<<endl;
            string tempo = "";
            tempo += s[ind];
            temp += s[ind];
            bool first = rec(ind+1,tempo, s, mp, dp);
            // cout<<" result of moving ahead with tempo: "<<tempo<<" -> "<<first<<endl; 
            bool second = rec(ind+1, temp, s, mp, dp);
            // cout<<" result of moving ahead with temp: "<<temp<<" -> "<<second<<endl;
            bool res = (first || second);
            if(res)
                dp[ind][temp] = 1;
            else
                dp[ind][temp] = -1;
            return res;
        }
        
        // cout<<"nothing found --> at ind: "<<ind<<" temp: "<<temp<<endl;
        temp.push_back(s[ind]);
        bool res = rec(ind+1, temp, s, mp, dp);
        if(res)
            dp[ind][temp] = 1;
        else
            dp[ind][temp] = -1;
        
        return res;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mp(wordDict.begin(), wordDict.end());
        string temp = "";
        map<int,map<string,int>> dp;
        return rec(0, temp, s, mp,dp);
    }
};