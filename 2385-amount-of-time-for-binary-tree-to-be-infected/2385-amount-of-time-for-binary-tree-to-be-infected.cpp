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
    
TreeNode* curr;
    
void rec(TreeNode *root, TreeNode *prev, unordered_map<TreeNode*, vector<TreeNode*>> &mp, int start)
    {
        if(!root)
            return;
        
        if(root->val == start )
            curr = root;
    
        if(root->left)
        {
            mp[root].push_back(root->left);
            rec(root->left, root,mp,start);
        }
        if(root->right)
        {
            mp[root].push_back(root->right);
            rec(root->right, root,mp,start);
        }
        if(prev)
            mp[root].push_back(prev);
    }
    
    
    
public:
    int amountOfTime(TreeNode* root, int start) {
        
        // if(root->left==NULL && root->right==NULL)
        //     return 0;
        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        rec(root,NULL,mp,start);
        
        queue<TreeNode*> q;
        q.push(curr);
        unordered_set<int> st;
        int level = -1;
        st.insert(curr->val);
        
        while(!q.empty())
        {
            level++;
            int size = q.size();
            // cout<<"at "<<level<<"th level: ";
            for(int i = 0 ; i<size ; i++)
            {
                TreeNode* currr = q.front();    
                st.insert(currr->val);
                // cout<<currr->val<<" ";
                q.pop();
                
                for(auto it: mp[currr])
                    if(st.find(it->val) == st.end())
                        q.push(it);
            }
            // cout<<endl;
        }
        
        return level;
    }
};