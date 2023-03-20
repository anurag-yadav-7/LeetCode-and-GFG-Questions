class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int N) {
        
        // cout<<"for N: "<<N<<endl;
        if( N == 0)
            return true;
        
        int n = flowerbed.size();
        int diff=0;
        
        if( flowerbed [0] == 0 && n == 1)
        {
            return true;
        }
        
        
        for(int i = 0 ; N>0 && i < n ; i++)
        {
            // cout<<" At index: " << i << endl;
            
            if( flowerbed[i] == 1 )
                diff=0;
            
            if(i==0 && i < n-1 && flowerbed[i] == 0 )
            {
                if(flowerbed [i+1] == 0)
                {
                    flowerbed [i] = 1;
                    N--;
                }
            }
            
            else if( flowerbed[i] == 0 && diff == 0)
            {
                // cout << " diff incremented: " << diff <<endl;
                diff++;
            }
            else if(i <= n-1 && flowerbed[i] == 0 && diff == 1)
            {
                if(i == n-1 )
                {
                    // cout << "last element 0 & diff == 1 so 0 ---> 1"<<endl;
                    flowerbed[i] = 1 ;
                    N-- ;
                }
                else if( flowerbed [i+1] != 1)
                {
                    // cout << "the normal condition.... 0 ---> 1"<<endl;
                    diff = 0 ;
                    flowerbed[i] = 1 ;
                    N-- ;
                }
            }
        }
        
        // cout<<" flowerbed: ";
        // for(auto it: flowerbed)
        //     cout<<it<<" ";
        // cout<<endl<<endl;
        
        if(N == 0)
            return true;
        return false;
    }
};