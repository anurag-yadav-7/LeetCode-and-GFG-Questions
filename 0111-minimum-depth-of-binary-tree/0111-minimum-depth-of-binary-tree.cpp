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
    int minDepth(TreeNode* root) {
        
    if (root == NULL) {
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int level = 1;
    while (q.size()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* curNode = q.front();
            q.pop();
            if (curNode->left == NULL && curNode->right == NULL) {
                return level;
            }
            if (curNode->left != NULL) {
                q.push(curNode->left);
            }
            if (curNode->right != NULL) {
                q.push(curNode->right);
            }
        }
        level++;
    }
    return level;
}
    };