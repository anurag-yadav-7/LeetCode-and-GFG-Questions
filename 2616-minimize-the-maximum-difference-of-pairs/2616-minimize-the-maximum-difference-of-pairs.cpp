class Solution {
public:


int minimizeMax(vector<int>& A, int p) {
        sort(A.begin(), A.end());
        int n = A.size(), left = 0, right = A[n - 1] - A[0];
        while (left < right) {
            int mid = (left + right) / 2, k = 0;
            for (int i = 1; i < n && k < p; ++i) {
                if (A[i] - A[i - 1] <= mid) {
                    k++;
                    i++;
                }
            }
            if (k >= p)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};





// class Solution {

//     bool check(int mid, vector<int> &nums, int p)
//     {
//         cout<<"at mid: "<<mid<<endl;
//         int n = nums.size();
//         vector<bool> visited(n,false);

//         int count = 0;
//             for(int i = 0 ; i < n ; i++)
//             {
//                 if(visited[i])
//                     continue;
//                 int mini = INT_MAX;
//                 int ind = n;
//                 cout<<"for "<<nums[i]<<": "<<endl;
//                 for(int j = i+1; j<n ; j++)
//                 {
//                     if(visited[j])
//                         continue;
//                     if(abs(nums[i]-nums[j]) <= mid)
//                     {
//                         cout<<" found: "<<nums[j]<<endl;
//                         if(nums[j] <= mini)
//                         {
//                             mini = nums[j];
//                             ind = j;
//                             cout<<"ind updated: "<<ind<<endl;
//                         }
//                     }
//                 }
                
//                 if(ind == n)
//                     continue;
//                 count++;
//                 cout<<"found a pair: "<<i<<" & "<<ind<<endl;
//                 visited[i] = true;
//                 visited[ind] = true;
//                 // cout<<"visited: "<<i<<" & "<<ind<<" : true"<<endl;
//             }
        
//         cout<<"count: "<<count<<endl;
        
//         return count >= p;
        
//     }
    
// public:
    
//     int minimizeMax(vector<int>& nums, int p) {
        
//         int n = nums.size();
//         if(n == 1)
//             return 0;
//         vector<int> temp = nums;
//         sort(temp.begin(), temp.end());
//         int maxdiff = temp[n-1]-temp[0];
        
//         int low = 0, high = maxdiff;
        
//         int mid;
//         int res = maxdiff;
//         while( low <= high )
//         {
//             mid = low + (high - low)/2;
//             cout<<"checking for mid: "<<mid<<" ---> ";
//             if(check(mid,nums,p))
//             {
//                 cout<<" passed "<<endl;
//                 res = mid;
//                 high = mid - 1;
//             }
//             else
//             {
//                 cout<<" failed "<<endl;
//                 low = mid + 1;
//             }
//             cout<<endl;
//         }
        
//         return res;
        
        
//     }
// };


