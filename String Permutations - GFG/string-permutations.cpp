//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void rec(int ind, string S,string temp, vector<string> &res, vector<int> &visited)
    {
        if(ind == S.length())
        {
            res.push_back(temp);
            return;
        }
        
        for(int i = 0 ; i<S.length(); i++)
        {
            if(visited[i])
                continue;
            
            visited[i] = 1;
            temp.push_back(S[i]);
            rec(ind+1,S,temp,res,visited);
            temp.pop_back();
            visited[i] = 0;
        }
        
    }
    
    vector<string> permutation(string S)
    {
        vector<int> visited(S.length(), 0);
        vector<string> res;
        sort(S.begin(),S.end());
        rec(0,S,"",res,visited);
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends