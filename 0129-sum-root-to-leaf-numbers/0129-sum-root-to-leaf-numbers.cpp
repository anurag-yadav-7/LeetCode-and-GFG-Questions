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
    string temp="";
    
    long long sum=0;
public:
    
    void dfs(TreeNode* root)
    {
        if(!root)
        {
            // cout<<"Entered NULL"<<endl;
            int temp1=stoi(temp);
            // cout<<"temp1: "<<temp1<<endl;
            sum+=temp1;
            return;
        }
        // cout<<"curr node: "<<root->val<<endl;
        temp.push_back((root->val)+48);
        if(!root->left && !root->right)
            dfs(root->left);
        
        if(root->left)
            dfs(root->left);
        
        if(root->right)
        dfs(root->right);
        
        temp.pop_back();
    }
    
    
    
    int sumNumbers(TreeNode* root) {
        
        dfs(root);
        return sum;
    }
};