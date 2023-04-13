class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        vector<int> res;
        int n=popped.size();
        int j=0;
        for( int i=0 ; i<n ; i++)
        {
            // if(res.size()>0)
            //     cout<<"res top: "<<res[res.size()-1]<<" and curr popped: "<<popped[j]<<endl;
            if(res.size()>0 && res[res.size()-1]==popped[j])
            {
                // cout<<"popped and j incremented..."<<endl;
                res.pop_back();
                i--;
                j++;
                continue;
            }
            // cout<<"pushed: "<<pushed[i]<<endl;
            res.push_back(pushed[i]);
        }
        
        while(res.size()>0 && res[res.size()-1]==popped[j])
            {
                // cout<<"curr top and popped same... hence popping..."<<endl;
                res.pop_back();
                j++;
            }
        
        if(j==n)
            return true;
        
        return false;
        
        
    }
};