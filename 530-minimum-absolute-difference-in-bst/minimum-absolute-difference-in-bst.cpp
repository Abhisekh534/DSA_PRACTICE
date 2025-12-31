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
    void inOrder(vector<int>&ans, TreeNode* root){
        if(!root) return;

        inOrder(ans, root->left);
        ans.push_back(root->val);
        inOrder(ans, root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        inOrder(ans, root);
       
        int mini = ans[1] - ans[0];

        for(int i=1; i<ans.size(); i++){
            mini = min(mini, ans[i] - ans[i-1]);
        }

        return mini;
    }
};