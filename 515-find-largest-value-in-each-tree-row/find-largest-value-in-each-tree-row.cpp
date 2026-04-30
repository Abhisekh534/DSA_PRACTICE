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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        queue<TreeNode*>q2;
        q.push(root);

        vector<int>vec;
        vec.push_back(root->val);
        while(!q.empty()){
            int maxi = INT_MIN;
            int flag = 0;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    q2.push(node->left);
                    maxi = max(maxi, node->left->val);
                    flag = 1;
                }
                if(node->right){
                    q2.push(node->right);
                    maxi = max(maxi, node->right->val);
                    flag = 1;
                }


            }
            if(flag) vec.push_back(maxi);
            q = q2;
            q2 = {};
        }

        return vec;
    }
};