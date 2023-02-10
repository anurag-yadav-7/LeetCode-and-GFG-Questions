//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
              // Code here
        int b = 0;
        int a = 0;
        int l = 0;
        int o = 0;
        int n = 0;
        for (auto ch : s) {
            if (ch == 'b') {
                b++;
            }
            else if (ch == 'a') {
                a++;
            }
            else if (ch == 'l') {
                l++;
            }
            else if (ch == 'o') {
                o++;
            }
            else if (ch == 'n') {
                n++;
            }
        }
        if (b == 0 || a == 0 || l == 0 || n == 0 || o == 0) {
            return 0;
        }
        int minSingleChar = min(b,min(a, n));
        int minDoubleChar = min(l, o);
        minDoubleChar /= 2;
        return min(minSingleChar, minDoubleChar);
    }

};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends