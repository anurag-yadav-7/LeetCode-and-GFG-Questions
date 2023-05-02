class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int index = 0;
        stack<int> st;
        string sta="";
        // int count= 0;
        while(i<n)
        {
            // cout<<"curr i: "<<i<<endl;
            // cout<<"curr index: "<<index<<endl;
            if(st.empty())
            {
                sta += (nums[i] + 48);
                st.push(nums[i++]);
                index++;
            }
            else
            {
                // cout<<"index-1: "<<index-1<<" ";
                if(((index-1) % 2) == 0)
                {
                    if(nums[i]==st.top())
                    {
                        // cout<<"skipped"<<endl;
                        i++;
                        // count++;
                    }
                    else
                    {
                        sta += (nums[i] + 48) ;
                        st.push(nums[i++]);
                        index++;
                    }
                }
                else
                {
                    sta += (nums[i] + 48);
                    st.push(nums[i++]);
                    index++;
                }
            }
            // cout<<"curr stack: "<<sta<<endl;        
        }
        
        int sizeee= st.size();
        if(sizeee % 2 != 0)
            sizeee--;
            
        return n-sizeee;
        
    }
};