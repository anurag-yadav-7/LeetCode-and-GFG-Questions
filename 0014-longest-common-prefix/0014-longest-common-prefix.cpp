class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==1)
            return strs[0];
        int minlen=INT_MAX,count=0;
        for(auto it: strs)
        {
            for(auto itr: it)
            {
                count++;
            }
            minlen=min(count,minlen);
            count=0;
        }
        
        int n=strs.size();
        
        int counter=0;
        bool flag=false;
        string res="";
        
        while(counter<minlen)
        {
            // cout<<"counter: "<<counter<<endl;
            
            for(int i=0;i<n-1;i++)
            {
                // cout<<"ith val: "<<strs[i][counter]<<endl;
                if(strs[i][counter]==strs[i+1][counter])
                {
                    flag=true;
                    // cout<<"flag: "<<flag<<endl;
                }
                else
                {
                    // cout<<"flag: "<<flag<<endl;
                    return res;
                }
            }
            
            if(flag==true)
                res+=strs[0][counter];
            
            
            // cout<<"curr prefix sum: "<<res<<endl;
            counter++;
        }
        
        
        return res;
    }
};