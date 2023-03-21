class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        sort(asteroids.begin(),asteroids.end());
        reverse(asteroids.begin(),asteroids.end());
        int n = asteroids.size();
        long long mymass = mass; 
        int first=n;
        bool flag = false;
        
        if(n == 1)
        {
            if( mass < asteroids[0])
                return false;
            else
                return true;
        }
        
        for(int i = 0; i < n ; i++)
        {
            if(asteroids[i] > mass )
            {
                continue;
            }
            else if(flag == false)
            {
                flag = true;
                first = i;
                mymass += asteroids[i];
                asteroids[i] = -1;
                continue;
            }
            else
            {
                mymass += asteroids[i];
                asteroids[i] = -1;
            }
        }
        
//         cout<<"semi updated asteroids: ";
//         for(auto it: asteroids)
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
//         cout<<"first -1: "<<first<<endl;
        
        for(int i = first-1; i >= 0; i--)
        {
            if(mymass < asteroids[i])
            {
                return false;
            }
            else
            {
                mymass += asteroids[i];
                asteroids[i] = -1;
            }
        }
        
        
        
        // cout<<"final updated asteroids: ";
        // for(auto it: asteroids)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return true;
    }
};
