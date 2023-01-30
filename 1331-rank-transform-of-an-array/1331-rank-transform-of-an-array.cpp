class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n=arr.size();
        
        
        map<int,int> mp;
        for(auto it: arr)
            mp[it]=0;
        int count=1;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            it->second=count;
            // cout<<it->first<<" "<<it->second<<endl;
            count++;
        }
        
        for(int i=0;i<n;i++)
        {
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};