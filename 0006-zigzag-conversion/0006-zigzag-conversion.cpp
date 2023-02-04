class Solution {
public:
    string convert(string s, int numRows) {
        
    bool flag=false;
    vector<int> arr[numRows];
    int n=s.length();
    int itr=0,i=0;
     
    if(numRows==1)
        return s;
    while(itr<n)
    {
        // cout<<s[itr]<<" ";
        if(i==0)
            flag=true;
        if(i==(numRows-1))
            flag=false;
        arr[i].push_back(s[itr]);
        if(flag)
            i++;
        if(flag==false)
            i--;
        itr++;
    }
    
    string res="";
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<arr[i].size();j++)
            res+=arr[i][j];
    }
    return res;
}
};