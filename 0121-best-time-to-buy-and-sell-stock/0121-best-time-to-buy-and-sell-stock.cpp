class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        st.push(INT_MAX);
        int diff=0;
    
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
        return diff;
    }
};