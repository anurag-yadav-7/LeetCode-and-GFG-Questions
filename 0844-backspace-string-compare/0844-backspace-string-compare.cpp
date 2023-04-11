class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string s1,s2;
        int n = s.length(), m = t.length();
        
        for(int i = 0 ; i<n ; i++)
        {
            if(s[i]=='#')
            {
                if(s1.length()>0)
                    s1.pop_back();
            }
            else 
                s1.push_back(s[i]);
        }    
        
        for(int i = 0 ; i<m ; i++)
        {
            if(t[i]=='#')        
            {
                if(s2.length()>0)
                    s2.pop_back();
            }
            else 
                s2.push_back(t[i]);
        }    
        
        if(s1==s2)
            return true;
        else
            return false;
            
    }
};