class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> arr(26,0);
        
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]-97]++;
            // cout<<"freq of: "<<s[i]<<"increased"<<endl;
        }
        
        string res="";
        int count=order.length();
        int i=0;
        while(i<order.length())
        {
            while(arr[order[i]-97]>0)
            {
                res.push_back(order[i]);
                arr[order[i]-97]--;
            }
            i++;
        }
        
        for(int j=0;j<s.length();j++)
        {
            while(arr[s[j]-97]>0)
            {
                res.push_back(s[j]);
                arr[s[j]-97]--;
            }
        }
        
        return res;
        
    
    }
};