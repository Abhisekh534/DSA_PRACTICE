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
    void solve(TreeNode* root, int nodeVal, int& maxi){
        if(!root) return;

        maxi = max(maxi, abs(root->val - nodeVal));

        solve(root->left, nodeVal, maxi);
        solve(root->right, nodeVal, maxi);

    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;

        int maxi = 0;
        solve(root, root->val, maxi);
        
        int x = max(maxAncestorDiff(root->left), maxAncestorDiff(root->right));
        
        maxi = max(maxi, x);
        return maxi;
    }
};