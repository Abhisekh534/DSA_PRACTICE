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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;

        queue<TreeNode*>q1;
        queue<TreeNode*>q2;

        q2.push(root);
        ans.push_back({root->val});

        while(!q2.empty()){
            q1 = q2;
            q2 = queue<TreeNode*>();

            vector<int> temp;

            while(!q1.empty()){
                TreeNode* node = q1.front();
                q1.pop();

                if(node->left){
                    temp.push_back(node->left->val);
                    q2.push(node->left);
                }
                if(node->right){
                    temp.push_back(node->right->val);
                    q2.push(node->right);
                }
            }
            if(!temp.empty()) ans.push_back(temp);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};