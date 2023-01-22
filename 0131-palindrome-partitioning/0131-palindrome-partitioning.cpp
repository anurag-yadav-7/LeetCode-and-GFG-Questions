class Solution {
public:
    
    void solve(int i,int j,string s,string &str,vector<string> &res,vector<vector<string>> &ans)
    {
        // cout<<"curr i: "<<i<<" j: "<<j<<endl;
        if(i>=s.length() || j>=s.length())
        {
            // cout<<"base case found...."<<endl;
            if(res.size()>1)
                ans.push_back(res);
            return;
        }
     
        string temp=s.substr(i,j);
        // cout<<"curr substr: "<<temp<<endl;
        if(!checkPall(temp))
        {
            // cout<<"Not pall...."<<endl;
            return;
        }
        // cout<<"pushed to res"<<endl;
        res.push_back(temp);
        if((i+j)==s.length())
        {
            // cout<<i+j<<" is equals to string len, hence pushed to ans..."<<endl;
            // if(res.size()==0)
            //     return;
            ans.push_back(res);
            res.pop_back();
            return;
        }
        for(int k=1;(i+j+k)<=s.length();k++)
        {
            // cout<<"k: "<<k<<endl;
            solve(i+j,k,s,str,res,ans);    
        }
        res.pop_back();
        // cout<<"popped from res..."<<endl;
        return;
        
            
    }
    
    bool checkPall(string s)
    {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<string> res;
        vector<vector<string>> ans;
        string str="";
        if(s.length()==1)
        {
            str+=s[0];
            res.push_back(str);
            ans.push_back(res);
            return ans;
        }
        
        for(int i=1;i<=s.length();i++)
            solve(0,i,s,str,res,ans);
        if(s.length()>1 && checkPall(s))
        {
            res.push_back(s);
            ans.push_back(res);
        }
        return ans;
    }
};