class Solution {
public:
    int pivotInteger(int n) {
        
        int tempsum = 0, totsum = (n*(n+1))/2;
        for(int i=1 ; i<=n ; i++)
        {
            tempsum = (i*(i+1))/2;
            if(tempsum == (totsum-tempsum+i))
                return i;
        }
        return -1;
        
    }
};