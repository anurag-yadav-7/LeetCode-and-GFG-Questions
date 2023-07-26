class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        
        int prod1 = 1, prod2 = 1;
        int maxLeft = INT_MIN, maxRight = INT_MIN;
        bool flag = false;
        
        for(int i = 0 ; i<n ; i++)
        {
            prod1 *= nums[i];
            prod2 *= nums[n-i-1];
            int temp1 = false, temp2 = false;
            
            if(prod1 == 0)
            {
                temp1 = true;
                flag = true;
                prod1 = 1;
            }
            
            if(prod2 == 0)
            {
                temp2 = true;
                flag = true;
                prod2 = 1;
            }
            
            if(!temp1)
            maxLeft = max(prod1,maxLeft);
 
            if(!temp2)
            maxRight = max(prod2,maxRight);
        }
        if(flag)
            return max(0, max(maxLeft,maxRight));
        return  max(maxLeft,maxRight);
    }
};