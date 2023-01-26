//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string s, int n)
    {
        // your code here
        string lower,upper;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' && s[i]<='z')
                lower.push_back(s[i]);
                
            else
                upper.push_back(s[i]);
        }
        
        sort(lower.begin(),lower.end());
        sort(upper.begin(),upper.end());
        // cout<<lower<<endl;
        // cout<<upper<<endl;
        int k=0,j=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                s[i]=lower[k];
                k++;
            }
            else
            {
                s[i]=upper[j];
                j++;
            }
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends