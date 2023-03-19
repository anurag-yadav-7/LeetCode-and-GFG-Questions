//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        vector<int> res;    
        
        for(auto it: A)
            mp2[it]++;
        
        int left=0,right=0;
        mp2[A[0]]--;
        if(mp2[A[0]]==0)
        {
            mp2.erase(A[0]);
        }
        right=mp2.size();
        res.push_back(left-right);
        for(int i=1;i<N;i++)
        {
            mp1[A[i-1]]++;
            mp2[A[i]]--;
            
            if(mp2[A[i]]==0)
            {
                mp2.erase(A[i]);
            }
            left=mp1.size();
            right=mp2.size();
            res.push_back(left-right);
            
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends