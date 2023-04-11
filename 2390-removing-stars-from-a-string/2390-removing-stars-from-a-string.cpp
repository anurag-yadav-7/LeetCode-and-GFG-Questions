class Solution {
public:
    string removeStars(string s) {
        
        string res="";
        int len = s.length();
        
        for(int i=0; i<len ; i++)
        {
            if(s[i]=='*')
                res.pop_back();
            else
                res.push_back(s[i]);
        }
        
        return res;
    }
};