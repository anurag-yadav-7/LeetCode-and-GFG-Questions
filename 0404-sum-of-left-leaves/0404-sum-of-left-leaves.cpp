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
    int sum=0;
    bool left=false;
    bool right=false;
public:
    
    
    void Preorder(TreeNode *root)
    {
        if(!root)
            return;
        
        if(root->left==NULL && root->right==NULL && left==true)
        {
            
            sum+=root->val;
                
        }
        
        left=true;
        Preorder(root->left);
        left=false;
        right=true;
        Preorder(root->right);
        right=false;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        Preorder(root);
        return sum;
        
    }
};