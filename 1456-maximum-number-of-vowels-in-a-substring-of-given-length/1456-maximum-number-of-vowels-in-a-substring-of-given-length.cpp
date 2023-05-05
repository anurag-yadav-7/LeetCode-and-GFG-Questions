class Solution {
public:
    int maxVowels(string s, int k) {
        
        
        int vowelcount=0;
        int res = 0;
        
        int loop = k;
        int i =0, n = s.length();
        
        while(loop--)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                vowelcount++;
            i++;
        }
        // cout<<"after loop i: "<<i<<" vowel count: "<<vowelcount<<endl;
        res = max(res,vowelcount);
        
        for(; i<n ; i++)
        {
            if(s[i-k] =='a' || s[i-k] =='e' || s[i-k] =='i' || s[i-k] =='o' || s[i-k] =='u')
                vowelcount--;
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                vowelcount++;
            
            // cout<<"after loop i: "<<i<<" vowel count: "<<vowelcount<<endl;
            res = max(res,vowelcount);
        }
        
        return res;
        
        
        
    }
};