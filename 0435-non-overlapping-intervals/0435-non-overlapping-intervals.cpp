class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count = 0;
        int n = intervals.size();
        int prevend = intervals[0][1];
        
        for(int i = 1 ; i<n ; i++)
        {
            int currstart = intervals[i][0];
            // cout<<"prevend: "<<prevend<<" currstart: "<<currstart<<endl;
            if(currstart < prevend)
            {
                count++;
                prevend = min(intervals[i][1], prevend);
            }
            else
            {
                prevend = intervals[i][1];
            }
        }
        
        return count;
        
    }
};  