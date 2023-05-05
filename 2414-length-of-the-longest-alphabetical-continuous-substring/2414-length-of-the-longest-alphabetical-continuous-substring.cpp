class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int n = s.length();
        int res = 1;
        int count=1;
        
        for(int i = 1; i<n ;i++)
        {
            if(s[i-1] == (s[i]-1))
            {
                count++;
            }
            else
                count = 1;
            res = max(res,count);
        }
        
        return res;
        
    }
};