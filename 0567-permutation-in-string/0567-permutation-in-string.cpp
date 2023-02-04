class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    
        int arr1[26]={0};
        int arr2[26]={0};
        int n=s1.length();
        int m=s2.length();
        int size=s1.length();
        
        if(n>m)
            return false;
        
        for(int i=0;i<n;i++)
            arr1[s1[i]-97]++;
        
        for(int i=0;i<size;i++)
            arr2[s2[i]-97]++;
        
        bool flag=false;
        for(int i=0;i<26;i++)
        {
            if(arr1[i]!=arr2[i])
            {
                flag=true;
                break;
            }
        }
        if(flag==false)
            return true;
        
        for(int i=size;i<m;i++)
        {
            arr2[s2[i-size]-97]--;
            // cout<<s2[i-size]<<" removed... " ;
            arr2[s2[i]-97]++;
            // cout<<s2[i]<<" pushed..."<<endl;
            flag=false;
            for(int i=0;i<26;i++)
            {
                // if(arr1[i]>0)
                //     cout<<"freq of "<<(char)(i+97)<<" in 1st: "<<arr1[i]<<" in 2nd: "<<arr2[i]<<endl;
                if(arr1[i]!=arr2[i])
                {
                    flag=true;
                    break;
                }
            }
            
            if(flag==false)
                return true;
        }
        
        return false;
    }
};