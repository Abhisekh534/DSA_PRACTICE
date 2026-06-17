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
    void dfs(int&count, TreeNode* root, int targetSum, long long currSum){
        if(root==NULL) return;

        currSum += root->val;

        if(currSum==targetSum) count++;

        dfs(count, root->left, targetSum, currSum);
        dfs(count, root->right, targetSum, currSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;

        int count = 0;

        dfs(count, root, targetSum, 0);

        count+=pathSum(root->left, targetSum);
        count+=pathSum(root->right, targetSum);

        return count;
    }
};