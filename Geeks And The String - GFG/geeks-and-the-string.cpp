//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
   
string removePair(string s) {
        string st="";
       
       int i=0;
       for(int i=0;i<s.length();i++)
       {
        //   cout<<"at i: "<<i<<endl;
            if(st.length()>0)
            {
                if(st[st.size()-1]==s[i])
                    st.pop_back();
                else
                    st.push_back(s[i]);
            }
            else
                st.push_back(s[i]);
            // cout<<"string st: "<<st<<endl;
       }
       if(st.length()==0)
       return "-1";
       return st;
       
       
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends