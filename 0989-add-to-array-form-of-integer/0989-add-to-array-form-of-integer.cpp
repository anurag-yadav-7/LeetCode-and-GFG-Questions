class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        vector<int> b;
        int temp=k;
        bool flag1=false,flag2=false,flag3=false;
        if(a.size()==1)
        {
            flag1=true;
            temp=temp+a[0];
        }
        else if(a.size()==2)
        {
            flag2=true;
            temp=temp+a[0]*10+a[1];
        }
        else if(a.size()==3)
        {
            flag3=true;
            temp=temp+a[0]*100+a[1]*10+a[2];
        }
        while(temp)
        {
            b.push_back(temp%10);
            temp=temp/10;
        }
        if(flag1==true)
        {
            reverse(b.begin(),b.end());
            return b;
        }
        if(flag2)
        {
            reverse(b.begin(),b.end());
            return b;
        }
        if(flag3)
        {
            reverse(b.begin(),b.end());
            return b;
        }
        
        
        reverse(a.begin(),a.end());
        int n=a.size(),m=b.size();
        
        int diff=abs(n-m);
        if(n>m)
        {
            while(diff--)
            {
                b.push_back(0);
            }
        }
        if(n<m)
        {
            while(diff--)
            {
                a.push_back(0);
            }
        }
        vector<int> res;
        int carry=0;
        
        
//         cout<<"a: "<<endl;
//         for(auto it: a)
//             cout<<it<<" ";
        
//         cout<<endl<<"b: "<<endl;
//         for(auto it: b)
//             cout<<it<<" ";
//         cout<<endl;
        
        for(int i=0;i<n;i++)
        {
            int curr=a[i]+b[i]+carry;
            // cout<<"currsum: "<<curr<<endl;
            res.push_back(curr%10);
            carry=curr/10;
        }
        
        if(carry==1)
            res.push_back(1);
        
        // for(auto it: res)
        //     cout<<it<<" ";
        // cout<<endl;
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};