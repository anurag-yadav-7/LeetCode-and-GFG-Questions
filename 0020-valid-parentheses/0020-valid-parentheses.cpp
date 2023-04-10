class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else if(st.size()>=1 && ((st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}') || (st.top()=='[' && s[i]==']' )))
                st.pop();
            else
                return false;
            cout<<"At char : "<<s[i]<<" stack size: "<<st.size()<<endl;
        }
        return st.empty();
                                                    
    }
};