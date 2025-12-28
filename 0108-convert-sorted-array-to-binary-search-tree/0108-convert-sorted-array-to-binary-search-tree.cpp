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
    void solve(TreeNode*& node, vector<int>&nums, int l, int e){
        if(l>e) return;

        int mid = l + (e-l)/2;

        node = new TreeNode(nums[mid]);

        solve(node->left, nums, l, mid-1);
        solve(node->right, nums, mid+1, e);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        solve(root, nums, 0, nums.size()-1);
        return root;
    }
};