class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        if(arr.size()==k)
        {
            long long currsum1=0;
            for(auto it: arr)
                currsum1+=it;
            if(currsum1/k>=threshold)
            {
                // cout<<"count: "<<1<<endl;
                return 1;
            
            }
            else
            {
                // cout<<"count: "<<0<<endl;    
                return 0;
            }
            
        }
        long long currsum=0;
        double curravg=0;
        int n=arr.size();
        int i=0;
        int count=0;
        for(int j=0;j<n;j++)
        {
            // cout<<"i: "<<i<<endl;
            // cout<<"j: "<<j<<endl;
            while(j<k)
            {
                currsum+=arr[j];
                j++;
                
                if(j==k)
                {
                    curravg=currsum/(k*1.0);
                    if(curravg>=threshold)
                        count++;
                }
            }
            // cout<<"currsum: "<<currsum<<endl;
            // cout<<"curravg: "<<curravg<<endl;
            
            currsum=k*curravg-arr[i];
            // cout<<"after extracting the sum of prev two, currsum: "<<currsum<<endl;
            i++;
            currsum+=arr[j];
            curravg=currsum/(k*1.0);
            // cout<<"updated curravg: "<<curravg<<endl;
            if(curravg>=threshold)
                count++;
           
        }
        // cout<<"count: "<<count<<endl<<endl;
        return count;
        
    }
};