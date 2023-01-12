class Solution {
public:
    
    void rec(int ind,vector<vector<string>> &res,vector<string> temp,string s)
    {
        if(ind==s.length())
        {
            res.push_back(temp); //res= 
            return;
        }
        
        // cout<<"ind: "<<ind<<endl;
        // cout<<"Entering into loop: "<<endl;
        for(int i=1;ind+i<=s.length();i++) // temp1= 
        {
            // cout<<"at i: "<<i<<endl;
            string temp1=s.substr(ind,i);
            // cout<<"current substr: "<<temp1<<endl;
            if(isPalindrome(temp1))
            {
                temp.push_back(temp1);
                rec(ind+i,res,temp,s);
                temp.pop_back();
            }
        }
        
    }
    
    bool isPalindrome(string temp)
    {
        for(int i=0;i<temp.size()/2;i++)
        {
            if(temp[i]!=temp[temp.size()-i-1])
                return false;
        }
        return true;
    }
    
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector<string> temp;
        
        rec(0,res,temp,s);
        
        return res;
    }
};