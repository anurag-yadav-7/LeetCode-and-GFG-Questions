class Solution {
public:
    string addBinary(string a, string b) {

        int n=a.length(),m=b.length();
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        // cout<<"reversed: a-> "<<a<<" b-> "<<b<<endl;
        if(n<m)
        {
            int diff=abs(n-m);
            while(diff--)
                a.push_back('0');
        }
        else if(n>m)
        {
            int diff=abs(n-m);
            while(diff--)
                b.push_back('0');
        }
        // cout<<"after making the size same: a-> "<<a<<" b-> "<<b<<endl;
        
        bool carry=false;
        string res="";
        
        for(int i=0;i<a.size();i++)
        {
            // cout<<"at i: "<<i<<" a[i]: "<<a[i]<<" b[i]: "<<b[i]<<endl;
            if(a[i]=='1' && b[i]=='0')
            {
                if(carry==true)
                {
                   res+='0'; 
                }
                else
                {
                    res+='1';
                }
            }
            else if(a[i]=='0' && b[i]=='1')
            {
                if(carry==true)
                {
                    res+='0'; 
                }
                else
                {
                    res+='1';
                }
            }
            else if(a[i]=='1' && b[i]=='1')
            {
                if(carry==true)
                {
                    res+='1';
                    carry=true;
                }
                else
                {
                    res+='0';
                    carry=true;
                }
            }
            else if(a[i]=='0' && b[i]=='0')
            {
                if(carry==true)
                {
                
                    res+='1';    carry=false;
                }
                else
                {
                    
                    res+='0';
                }
            }
        }
        
        if(carry==true)
                res+='1';
        reverse(res.begin(),res.end());
        
        return res;
    }
};