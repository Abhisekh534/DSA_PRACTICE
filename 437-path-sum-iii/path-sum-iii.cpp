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
    void solve(int&count, TreeNode* node, int targetSum, long long sum){
        if(node==NULL) return;

        if(sum+node->val==targetSum){
            count++;
        }

        solve(count, node->left, targetSum, sum + node->val);

        solve(count, node->right, targetSum, sum + node->val);

    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        
        int count = 0;
        solve(count, root, targetSum, 0);

        count+=pathSum(root->left, targetSum);
        count+=pathSum(root->right, targetSum);
        //to make the next level nodes starting point recursively

        return count;
    }
};