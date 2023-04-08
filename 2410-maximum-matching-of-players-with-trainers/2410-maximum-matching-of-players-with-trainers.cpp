class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        

        int n = players.size();
        int m = trainers.size();
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        
        
        int count=0;
        int ptr1=0,ptr2=0;
        
        while(ptr1<n && ptr2<m)
        {
            if(players[ptr1]<=trainers[ptr2])
            {
                count++;
                ptr1++;
                ptr2++;
            }
            else 
            {
                ptr2++;
            }
        }
        
        
        return count;

    }
};