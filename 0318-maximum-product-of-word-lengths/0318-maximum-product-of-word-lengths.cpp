class Solution {
public:


    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        
        vector<vector<bool>> hash(n,vector<bool> (26,false));
        
        for(int i=0; i<n ; i++)
        {
            for(int j=0; j<words[i].length() ; j++)
                hash[i][words[i][j]-97] = true;
        }
        
        int res = 0;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                bool flag=false;
                for(int k=0 ; k<26; k++)
                    if(hash[i][k] && hash[j][k])
                    {
                        flag=true;
                        break;
                    }
                if(flag==false)
                {
                    int temp = words[i].length()*words[j].length();
                    res = max(res,temp);
                }
            }
        }
        return res;
        
        
    }
};