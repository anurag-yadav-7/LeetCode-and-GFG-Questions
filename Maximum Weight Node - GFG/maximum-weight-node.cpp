//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> edge)
  {
      // code here
      int res=0,currmax=0;
      int n=edge.size()-1;
      unordered_map<int,int> mp;
      
      
      for(int i=0;i<edge.size();i++)
      {
          if(edge[i]!=-1)
            {
                mp[edge[i]]+=i;
                // cout<<"sum value of node: "<<edge[i]<<"increased to: "<<mp[edge[i]]<<endl;
                if(mp[edge[i]]>currmax)
                {
                    
                    currmax=mp[edge[i]];
                    res=edge[i];
                    // cout<<"updating the currmax to: "<<currmax<<" and res: "<<res<<endl;
                }
                else if(mp[edge[i]]==currmax)
                    {
                        res=max(edge[i],res);
                        // cout<<"Equal to previous value hence new res: "<<res<<endl;
                    }
            }
      }
      
    //   for(auto it=mp.begin();it!=mp.end();it++)
    //   {
    //     int currsum=0;
    //     // cout<<it->first<<": ";
    //     for(auto itr: it->second)
    //         {
    //             // cout<<itr<<" ";
    //             currsum+=itr;
    //         }
    //     // cout<<endl;
    //     // cout<<"currsum: "<<currsum<<endl;
    //     if(currsum>currmax)
    //         {
    //             currmax=currsum;
    //             res=it->first;
    //         }
    //     else if(currsum==currmax)
    //     {
    //         res=max(it->first,res);
    //     }
    //   }
      return res;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends