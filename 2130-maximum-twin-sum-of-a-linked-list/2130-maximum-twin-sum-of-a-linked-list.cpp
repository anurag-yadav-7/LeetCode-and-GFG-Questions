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
    int pairSum(ListNode* head) {
        
        
        ListNode *slow=head,*fast=head;
        
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        cout<<slow->val<<endl;
        
        ListNode *curr=slow,*prev=NULL,*next=slow;
        
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        int res=0;
        fast=head;    
        slow=prev;
        while(slow && fast)
        {
            // cout<<"current slow: "<<slow->val<<" fast: "<<fast->val<<endl;
            int temp=slow->val+fast->val;
            res=max(temp,res);
            slow=slow->next;
            fast=fast->next;
        }
        return res;
        
    }
};