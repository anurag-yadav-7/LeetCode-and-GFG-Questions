class Solution {
public:
    
    bool checkPattern(string curr,string s1)
    {
        int n=s1.length();
        string temp=curr;
        // cout<<"comparing: "<<curr<<" with "<<s1<<endl;
        while(curr.length()<n)
        {
            curr+=temp;
            // cout<<"curr multiplied to: "<<curr<<endl;
            if(curr==s1)
            {
                // cout<<"return true"<<endl;
                return true;
            }
        }
        if(curr==s1)
            return true;
                // cout<<"return false"<<endl;
        return false;
    }
        
    string gcdOfStrings(string str1, string str2) {
        
        string curr;
        if(str2.length()<=str1.length())
        {
            curr=str2;
            for(int i=0;i<str2.length();i++)
            {
                if(curr.length()==0)
                    return "";
                // cout<<"curr string: "<<curr<<endl;
                string temp=curr;
                bool c1=checkPattern(curr,str2);
                bool c2;
                if(c1)
                    c2=checkPattern(curr,str1);
                if(c1&&c2)
                    return curr;
                curr.pop_back();
            }
        }
        else if(str2.length()>str1.length())
        {
            curr=str1;
            for(int i=0;i<str1.length();i++)
            {
                if(curr.length()==0)
                    return "";
                // curr+=str1[i];
                
                // cout<<"curr string: "<<curr<<endl;
                string temp=curr;
                bool c1=checkPattern(curr,str1);
                bool c2=checkPattern(curr,str2);
                if(c1&&c2)
                    return curr;
                curr.pop_back();
            }
        }
            return "";
            
    }
        
};