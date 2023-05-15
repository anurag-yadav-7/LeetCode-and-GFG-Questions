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
    ListNode* swapNodes(ListNode* head, int k) {
        int count = k-1;
        ListNode* fast = head;
        ListNode* curr = head;
        
        while(count--)
        {
            fast = fast->next;        
        }
        
        ListNode* first = fast;
        ListNode* curr2 = head;
        while(fast->next)
        {
            fast = fast->next;
            curr2 = curr2->next;
        }
        ListNode* second = curr2;
        swap(first->val,second->val);
        
        return head;
        
    }
};