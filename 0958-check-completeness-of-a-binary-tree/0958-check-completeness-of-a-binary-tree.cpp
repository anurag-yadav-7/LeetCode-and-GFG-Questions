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
public:
    bool isCompleteTree(TreeNode* root) {
        
        bool flag = false;
        queue<TreeNode *> q;
        q.push(root);
        
        while(q.size())
        {
            int n=q.size();
            // cout<<"new level: ";
            TreeNode* temp= new TreeNode(-1);
            
            while(n--)
            {
                TreeNode *curr=q.front();
                q.pop();
                
                if(flag== false &&  curr->val==-1)
                    flag=true;
                    
                else if(flag== true && curr->val!=-1)
                    return false;
                
                if(curr->val!=-1)
                {
                    if(curr->left)
                        q.push(curr->left);
                    else
                        q.push(temp);
                    if(curr->right)
                        q.push(curr->right);
                    else
                        q.push(temp);
                }   
            }
        }
        return true;
    }
};




