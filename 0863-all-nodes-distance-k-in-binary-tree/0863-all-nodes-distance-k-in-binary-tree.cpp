/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    void rec(TreeNode *root, TreeNode *prev, unordered_map<TreeNode*, vector<TreeNode*>> &mp)
    {
        if(!root)
            return;
        
        if(root->left)
        {
            mp[root].push_back(root->left);
            rec(root->left, root,mp);
        }
        if(root->right)
        {
            mp[root].push_back(root->right);
            rec(root->right, root,mp);
        }
        if(prev)
            mp[root].push_back(prev);
    }
    
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        rec(root,NULL,mp);
        
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> st;
        int level = 0;
        st.insert(target);
        
        
        while(!q.empty())
        {
            int size = q.size();
            
            if(level == k)
            {
                for(int i = 0 ; i<size ; i++)
                {              
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
                
            
            
            for(int i = 0 ; i<size ; i++)
            {
                TreeNode* curr = q.front();    
                st.insert(curr);
                q.pop();
                
                for(auto it: mp[curr])
                    if(st.find(it) == st.end())
                        q.push(it);
            }
            level++;
        }
        
        
        return {};
    }
};