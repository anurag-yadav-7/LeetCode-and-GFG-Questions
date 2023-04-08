class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        // Make difficult and profit pair vector jobs
        vector<pair<int,int>>jobs;
        
        int d_size = difficulty.size();
        for(int i=0;i<d_size;i++)
            jobs.push_back(make_pair(difficulty[i],profit[i]));
        
        // sort jobs difficulty => O ( DLogD )
        sort(jobs.begin(),jobs.end());
        
        // sort workers array difficulty => O ( WLogW ) 
        sort(worker.begin(),worker.end());
        
        int w_size = worker.size();
        int maxProfit = 0;
        int cprofit = 0;
        int cjob = 0;
        
        // Loop through workers array to find profit for each worker => O ( W + D )
        for(int i=0;i<w_size;i++)
        {
            // find max profit for worker[i] which is cprofit
            // As jobs and workers are sorted, cprofit is always max for any difficulty range
            while(cjob<d_size && jobs[cjob].first<=worker[i])
            {
                cprofit = max(cprofit,jobs[cjob].second);
                cjob++;
            }
            
            // update total max profit
            maxProfit+= cprofit;
        }
        
        return maxProfit;
    }
};