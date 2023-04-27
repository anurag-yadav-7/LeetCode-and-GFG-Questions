class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        
        if(num ==0 )
            return true;
        
        for(int i = 1; i<num ; i++)
        {
            string orig = to_string(i);
            reverse(orig.begin(),orig.end());
            int chck = stoi(orig);
            if(chck + i == num)
                return true;
        }
        return false;
        
    }
};