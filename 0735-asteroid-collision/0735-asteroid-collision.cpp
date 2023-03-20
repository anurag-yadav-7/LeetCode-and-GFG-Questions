class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        
        stack<int> st;
        
        int n = ast.size();
        
        for(int i = 0 ; i < n ; i++ )
        {
            int curr = ast[i];
            if(st.empty())
            {
                st.push(ast[i]);
                continue;
            }
            
            if( st.top()>0 && curr < 0)
            {
                int topper = st.top();
                // cout<<"current top: "<<topper<<" ast:  "<<curr<<endl;
                
                // st.pop();
                if(abs(topper) > abs(curr))
                {
                    // cout<<"top wins"<<endl;
                    continue;        
                }
                
                if(abs(topper) == abs (curr))
                {
                    // cout<<" both burst"<<endl;
                    st.pop();
                    continue;
                    
                }
                
                else
                {
                    while(!st.empty() && st.top()>0 && abs(st.top()) < abs(curr))
                    {
                        // cout<<"currtop: "<<st.top(); 
                        // cout<<" top keeps loosing..."<<endl;
                        st.pop();
                    }
                    if(!st.empty() && st.top()>0 && abs(st.top()) == abs (curr))
                    {
                        // cout<<" both burst"<<endl;
                        st.pop();
                        continue;
                    }
                    if(!st.empty() && st.top()>0)
                    {
                        // cout<<"top wins"<<endl;
                        continue;
                    }
                    else if(st.empty())
                    {
                        // cout<<" all tops cleared... pushing curr now"<<endl;
                        st.push(curr);
                    }
                    else if(!st.empty() && st.top()<0)
                    {
                        st.push(curr);
                        // cout<<"pushed curr"<<endl;
                    }
                }
            }
            else
            {
                // cout<<" non - harmful cases found...."<<endl;
                st.push(curr);
            }
            
        }
        
        vector<int> res;
        while(!st.empty())
        {
            int tip=st.top();
            res.push_back(tip);
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};