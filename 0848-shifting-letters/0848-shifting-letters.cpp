class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        string res = s;
        int n = shifts.size();
        vector<long long> prefix (n,0);
        
        prefix[0] = shifts[n-1];
        
        int i = 0;
        for(int j = n-1 ; j>=0 ; j--)
        {
            if( i==0 )
                prefix[i++] = shifts[j];
            else
            {
                prefix[i] = prefix[i-1] + shifts[j];
                i++;
            }
        }
        
//         for (auto it: prefix)
//             cout<<it<<" ";
//         cout<<endl;
        
        int j = 0;
        for(int i = n-1 ; i>=0  ; i--)
        {
            prefix[i] = prefix[i] % 26;
            // cout<<"incrementing "<<res[j]<<" by: "<<prefix[i]<<endl;
            if(res[j] + prefix[i] > 122)
            {
                res[j] = ((res[j] - 97 + prefix[i])%26) + 97;

                // cout<<"after updating: "<<(res[j])<<endl;
            }
            else
            {
                // cout<<"res[j]: "<<res[j]<<" and prefix: "<<prefix[i]<<endl;
                res[j] = res[j] + prefix[i];
                // cout<<"after updating: "<<res[j]<<endl;
            }
            j++;
        }
            
            
        return res;
    }
};