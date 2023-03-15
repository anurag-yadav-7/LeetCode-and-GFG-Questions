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
            vector<int> checker;
            
            while(n--)
            {
                TreeNode *curr=q.front();
                q.pop();
                checker.push_back(curr->val);
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
                
                // cout<<curr->val<<" ";
                
            }
            // cout<<endl;
            int size = checker.size();
            
            for(int i = 0 ; i< size; i++)
            {
                if(flag==false &&  checker[i]==-1)
                {
                    flag=true;
                }
                else if(flag==true && checker[i]!=-1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};




