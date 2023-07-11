/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    
void rec(TreeNode *root, int prev, unordered_map<int, vector<int>> &mp, int start)
    {
        if(!root)
            return;
        
        if(root->left)
        {
            mp[root->val].push_back(root->left->val);
            rec(root->left, root->val ,mp,start);
        }
        if(root->right)
        {
            mp[root->val].push_back(root->right->val);
            rec(root->right, root->val,mp,start);
        }
        if(prev)
            mp[root->val].push_back(prev);
    }
    
    
    
public:
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<int, vector<int>> mp;
        rec(root,0,mp,start);
        
        queue<int> q;
        q.push(start);
        unordered_set<int> st;
        int level = 0;
        st.insert(start);
        
        while(!q.empty())
        {
            level++;
            int size = q.size();
            // cout<<"at "<<level<<"th level: ";
            for(int i = 0 ; i<size ; i++)
            {
                int currr = q.front();    
                st.insert(currr);
                // cout<<currr->val<<" ";
                q.pop();
                
                for(auto it: mp[currr])
                    if(st.find(it) == st.end())
                        q.push(it);
            }
            // cout<<endl;
        }
        
        return level-1;
    }
};