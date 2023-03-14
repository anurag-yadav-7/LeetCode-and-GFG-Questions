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
    priority_queue<string,vector<string>,greater<string>> pq;
public:
    
    void dfs(TreeNode* root)
    {
        if(!root)
        {
            string ulttemp=temp;
            reverse(ulttemp.begin(),ulttemp.end());
            // cout<<"leaf node encountered.... original string: "<<temp<<endl;
            temp.pop_back();
            pq.push(ulttemp);
            return;
        }
        
        // cout<<"curr node: "<<(char)((root->val)+97)<<endl;
        temp.push_back((root->val)+97);
        
        if(!root->left && !root->right)
        {
            dfs(root->left);
            return;
        }
        
        if(root->left)
            dfs(root->left);
        
        if(root->right)
            dfs(root->right);
        
//         if(temp.length()>0)
        temp.pop_back();
        
    }
    
    
    string smallestFromLeaf(TreeNode* root) {
        
        dfs(root);
        
        return pq.top();
    }
};