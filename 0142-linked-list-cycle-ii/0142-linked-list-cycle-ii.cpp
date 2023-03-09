/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        if(head==nullptr)
            return NULL;
        if(head!=nullptr && head->next!=nullptr && head->next->next==head)
            return head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                // cout<<"YES"<<endl;
                break;
            }
        }
        if(slow!=fast)
            return NULL;
        slow=head;
        // count=-1;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return fast->next;
    }
};