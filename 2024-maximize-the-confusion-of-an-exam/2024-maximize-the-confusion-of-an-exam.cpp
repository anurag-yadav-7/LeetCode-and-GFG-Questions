class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int n = answerKey.length();
        int low = 0, high = 1;
        int count = 0;
        int res = 0,res2 = 0;
        if(n==1)
            return 1;
        
        if(answerKey[low] == 'F')
            count++;
        
        while(count <= k && high<n)
        {
            if(answerKey[high] == 'F')
            {
                count++;
                if(count > k)
                {
                    while(low<= high && count > k)
                    {
                        if(answerKey[low] == 'F')
                            count--;
                        low++;
                    }
                }
            }
            res = max(res,high-low+1);
            high++;
        }
        
        
        low = 0, high = 1, count = 0;
        if(answerKey[low] == 'T')
            count++;
        
        while(count <= k && high<n)
        {
            if(answerKey[high] == 'T')
            {
                count++;
                if(count > k)
                {
                    while(low<= high && count > k)
                    {
                        if(answerKey[low] == 'T')
                            count--;
                        low++;
                    }
                }
            }
            res2 = max(res2,high-low+1);
            high++;
        }
        
        res = max(res,res2);
        return res;
    }
};