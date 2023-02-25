class Solution {
public:
    int maximumDifference(vector<int>& prices) {
        
        stack<int> st;
        st.push(INT_MAX);
        int diff=-1;
    
        for(auto it: prices)
        {
            if(it<st.top())
            {
                st.pop();
                st.push(it);
            }
            else
            {
                int  temp=it-st.top();
                if(temp>diff)
                {
                    diff=temp;
                }
            }
        }
        
        if(diff==0)
            return -1;
            
            return diff;
    }
};