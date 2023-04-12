class Solution {
public:
    string simplifyPath(string path) {
        
        int n  = path.length();
        stack<string> st;
        
        for(int i=0 ; i<n ; i++)
        {
            // cout<<"new iteration: i-->"<<i<<endl;
            // cout<<"current char: "<<path[i]<<endl;
            if(path[i]=='/')
            {
                string temp="";
                i++;
                
                while(i<n && path[i]=='/')
                    i++;
                
                while(i<n && path[i]!='/')
                {
                    temp += path[i];
                    i++;
                }
                
                if(path[i]=='/')
                    i--;
                
                // cout<<"Made string: "<<temp<<endl;
                
                string comp="..";
                // cout<<"stack size: "<<st.size()<<endl; 
                if(temp==comp && st.size()>0)
                {
                    // cout<<"popping from the stack: "<<st.top()<<endl;
                    st.pop();
                    continue;
                }
                else if(temp==comp)
                {
                    continue;
                }
                else if(temp=="")
                {
                    // cout<<"nothing found... so continue"<<endl;
                    continue;
                }
                else if(temp!=".")
                {
                    // cout<<"Dot found... so do nothing..."<<endl;
                    st.push(temp);
                }
            }
        }
        
        stack<string> st2;
        while(!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }
        
        if(st2.size()==0)
            return "/";
        string res="";
        while(st2.size())
        {
            res.push_back('/');
            res += st2.top();
            st2.pop();
        }
        
        if(res.size()==0)
            return "/";
        
        if(res[res.size()-1]=='/' && res.size()>0)
            res.pop_back();
        
        
        return res;
    }
};