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
    int numComponents(ListNode* head, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int count=0;
        int n=nums.size();
        unordered_set<int> st(nums.begin(),nums.end());
        bool flag=false;
        while(head)
        {
            flag=false;
            while(head && st.find(head->val)!=st.end())
            {
                flag=true;
                head=head->next;
            }
            
            if(flag)
                count++;
            
            if(head && st.find(head->val)==st.end())
            {
                head=head->next;
            }            
        }
        
        return count;
        
    }
};