class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        reverse(digits.begin(),digits.end());
        vector<int> res;
        
        int carry=1;
        
        int n=digits.size();
        
        for(int i=0;i<n;i++)
        {
            int temp=digits[i]+carry;
            res.push_back(temp%10);
            carry=temp/10;
        }
        
        if(carry==1)
            res.push_back(1);
        
        reverse(res.begin(),res.end());
        return res;
        
        
    }
};