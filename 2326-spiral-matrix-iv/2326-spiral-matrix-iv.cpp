/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m,vector<int> (n,-1));
        
        int top=0,bottom=m-1,right=n-1,left=0;
        
        while(head && top<=bottom && left<=right)
        {
            
     
            for(int i = left;head && i<=right; i++)
            {
                res[top][i] = head->val;
                head=head->next;
            }
            top++;
            
            for(int i = top ; head && i<=bottom ; i++)
            {
                res[i][right] = head->val;
                head= head->next;
            }
            right--;
      
            if(left<=right)
            {
                for(int i=right; head && i>=left ; i--)
                {
                    res[bottom][i] = head->val;
                    head= head->next;
                }
                bottom--;
            }
            
            if(top<=bottom)
            {
                for(int i=bottom; head && i>=top ; i--)
                {
                    res[i][left] = head->val;
                    head= head->next;
                }
                left++;
            }
         }
   
        return res;
    }
};