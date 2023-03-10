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
    ListNode *temp;
    vector<int> arr;
    bool flag=false;
public:
    Solution(ListNode* head) {
        
      temp=head;  
    }
    
    int getRandom() {
        while(temp && flag==false)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        flag=true;
        // for(auto it: arr)
        //     cout<<it<<" ";
        int size=arr.size();
        int ind;
        // for(int i=0;i<50;i++)
        // {
            ind=rand()%size;
        //     cout<<ind<<" ";
        // }
        return arr[ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */