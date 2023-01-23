class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,vector<int>> mp;
        vector<bool> check(1001,false);
        if(n==1)
            return 1;
        
        for(int i=0;i<trust.size();i++)
        {
            mp[trust[i][1]].push_back(trust[i][0]);
            check[trust[i][0]]=true;
        }
        
        for(auto it: mp)
        {
            // cout<<endl<<it.first<<": ";
            // for(auto itr: it.second)
            //     cout<<itr<<" ";
                if(it.second.size()==(n-1) && check[it.first]==false)
                return it.first;
        }
        return -1;
    }
};