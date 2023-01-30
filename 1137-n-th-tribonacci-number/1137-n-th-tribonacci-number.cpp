class Solution {
public:
    int tribonacci(int n) {
        vector<int> vec(n+1,0);
        if(n>=2)
            vec[2]=1;
        if(n>=1)
            vec[1]=1;
        if(n>=0)
            vec[0]=0;
        
        // if(n==0) //|| n==1 || n==2)
        //     return vec[n];
        
        for(int i=3;i<=n;i++)
        {
            vec[i]=vec[i-3]+vec[i-1]+vec[i-2];    
            // cout<<i<<": "<<vec[i]<<endl;
        }
        
        return vec[n];
        
    }
};