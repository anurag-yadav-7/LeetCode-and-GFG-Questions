class Solution {
public:
    string truncateSentence(string s, int k) {
        
        int len = s.length();
        string str = "";
        string res = "";
        int original = k;
        for( int i = 0 ; i < len ; i++)
        {
            if(k == 0)
                break;
                
            if(s[i]==' ')
            {
                if(k == original)
                    res = str;
                else
                    res = res + ' '+ str;
                // cout<<"space found... curr str: "<<str<<" curr res: "<<res<<endl;
                str = "";
                k--;
                continue;
            }
            
            str = str + s[i] ;
        }
        
        if(str.length()>0)
        {
            if(k == original)
                res = str;
            else
                res += (' '+ str );
                
            str = "";
        }
        
        s = res;
        // cout<<"s: "<<s<<endl;
        return s;
    }
};