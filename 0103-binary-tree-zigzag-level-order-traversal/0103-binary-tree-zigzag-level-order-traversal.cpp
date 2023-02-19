/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> zigzagLevelOrder(TreeNode *root)
        {
            if(!root)
                return {};
            if((root->left==NULL && root->right==NULL))
                return {{root->val}};
            
            
            bool flag = false;
            deque<TreeNode*> q;
            q.push_back(root);
            vector<vector < int>> res;
            while (!q.empty())
            {
                // cout<<"Flag: "<<flag<<endl;
                int size = q.size();

                vector<int> level;
                for (int i = 0; i < size; i++)
                {
                    
                    TreeNode *temp;
                    if (!flag)
                    {
                        temp = q.front();
                        q.pop_front();
                        // cout << "curr q.front(): " << temp->val << endl;
                        if (temp->left)
                        {
                            q.push_back(temp->left);
                            // cout<<"pushed to the back: "<<temp->left->val<<endl;
                        }
                        if (temp->right)
                        {
                            q.push_back(temp->right);
                    
                            // cout<<"pushed to the back: "<<temp->right->val<<endl;
                        }
                    }
                    else
                    {
                        temp = q.back();
                        q.pop_back();
                        // cout << "curr q.back(): " << temp->val << endl;
                        if (temp->right)
                        {
                        
                            // cout<<"pushed to the front: "<<temp->right->val<<endl;    
                            q.push_front(temp->right);
                        }
                        if (temp->left)
                        {
                            q.push_front(temp->left);
                    
                            // cout<<"pushed to the front: "<<temp->left->val<<endl;
                        }
                    }

                    level.push_back(temp->val);
                    
                }
                res.push_back(level);
                flag = !flag;
            }

            return res;
        }
};