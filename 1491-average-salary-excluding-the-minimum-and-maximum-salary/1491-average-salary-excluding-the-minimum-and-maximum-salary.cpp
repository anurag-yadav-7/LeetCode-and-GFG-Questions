class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto it: salary)
        {
            mini = min(mini, it);
            sum += it;
            maxi = max(maxi, it);
        }
        sum = sum - mini - maxi;
        int count = salary.size();
        // cout<<"mini: "<<mini<<" maxi: "<<maxi<<" count: "<<count<<endl;
        return sum/(double)(count-2.0);
    }
};