//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&st, int sizeOfStack)
    {
        if(sizeOfStack == 2)
            {
                int temp = st.top();
                st.pop();
                st.pop();
                st.push(temp);
                return;
            }
        // code here.. 
        vector<int> temp;
        
        
        int count = sizeOfStack/2;
        
        while(count--)
        {
            temp.push_back(st.top());
            st.pop();
        }
        st.pop();
        
        while(temp.size())
        {
            st.push(temp.back());
            temp.pop_back();
        }
        
        
        return;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends