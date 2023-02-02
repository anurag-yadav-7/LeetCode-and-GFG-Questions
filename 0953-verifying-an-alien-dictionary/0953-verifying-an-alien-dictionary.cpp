class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i=0;i<order.length();i++)
            mp[order[i]]=i;
        
        for(int i=1;i<words.size();i++)
        {
            // cout<<"currently comparing: "<<words[i][0]<<" and "<<words[i-1][0]<<endl;
            
            if(mp[words[i][0]]<mp[words[i-1][0]])
            {
                // cout<<"less than earlier.... so returning false..."<<endl;
                return false;
            }
            else if(mp[words[i][0]]==mp[words[i-1][0]])
            {
                // cout<<"both equal.... so itr++ ....."<<endl;
                int itr=1;
                int lim=min(words[i].length(),words[i-1].length());
                while(itr<lim && mp[words[i][itr]]==mp[words[i-1][itr]])
                {
                    itr++;
                }
                // cout<<"final itr: "<<itr<<endl;
                if(itr==lim)
                {
                    // cout<<"words limit reached.... so checking..."<<endl;
                    if(words[i].length()<words[i-1].length())
                        return false;
                    else
                        continue;
                }
                else if(mp[words[i][itr]]<mp[words[i-1][itr]])
                {
                    // cout<<"less than earlier.... so returning false..."<<endl;
                    return false;
                }
            }
            // else
            //     cout<<"order followed.... continue..."<<endl;
        }
        return true;
    }
};