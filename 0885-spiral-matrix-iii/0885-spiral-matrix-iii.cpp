class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        vector<vector<int>> res;
        int top=rStart,bottom = rStart+1, left=cStart-1, right=cStart+1;
        int count=1;
        bool flag=false;
        while(left>=0 || right<=cols-1 || top>=0 || bottom<=rows-1)
        {
            // cout<<"top: "<<top<<" left: "<<left<<" right: "<<right<<" bottom: "<<bottom<<endl;
//             for(auto it: res)
//             {
//                 for(auto itr: it)
//                     cout<<itr<<" ";
//                 cout<<endl;
//             }
//             cout<<endl;
            
            int j;
            if(flag==true)
                j = left+2;
            else 
                j=left+1;
            
            for(; j<=right ; j++)
            {
                flag=true;
                if(j>=0 && j<=cols-1 && top>=0)
                    {
                     res.push_back({top,j});
                    }
            }
            top--;
            
//             cout<<"top: "<<top<<endl;
//             for(auto it: res)
//             {
//                 for(auto itr: it)
//                     cout<<itr<<" ";
//                 cout<<endl;
//             }
//             cout<<endl;
            
            for(int i=top+2 ; i<=bottom ; i++)
            {
                if(i>=0 && i<=rows-1 && right<=cols-1)
                    {
                     res.push_back({i,right});
                    }
            }
            right++;
            
//             cout<<"right: "<<right<<endl;
            
//             for(auto it: res)
//             {
//                 for(auto itr: it)
//                     cout<<itr<<" ";
//                 cout<<endl;
//             }
//             cout<<endl;
            
            
            for(int i= right-2 ; i>=left ; i--)
            {
                if(i>=0 && i<=cols-1 && bottom<=rows-1)
                    {
                     res.push_back({bottom,i});
                    }
            }
            bottom++;
            
//             cout<<"bottom: "<<bottom<<endl;
            
//             for(auto it: res)
//             {
//                 for(auto itr: it)
//                     cout<<itr<<" ";
//                 cout<<endl;
//             }
//             cout<<endl;
            
            for(int i= bottom-2; i>=top; i--)
            {
                if(i>=0 && i<=rows-1 && left>=0)
                    {
                     res.push_back({i,left});
                    }
            }
            left--;
            
            // cout<<"left: "<<left<<endl;
            // for(auto it: res)
            // {
            //     for(auto itr: it)
            //         cout<<itr<<" ";
            //     cout<<endl;
            // }
            // cout<<endl;
        }
        return res;
    }
};