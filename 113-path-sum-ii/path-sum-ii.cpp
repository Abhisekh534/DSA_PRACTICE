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
    void dfs(vector<vector<int>>&ans, vector<int>&temp, TreeNode* node, int targetSum, int sum){
        sum+=node->val;
        temp.push_back(node->val);

        if(!node->left && !node->right){

            if(sum==targetSum) ans.push_back(temp);
        
        }else{
            
            if(node->left) dfs(ans, temp, node->left, targetSum, sum);
            if(node->right) dfs(ans, temp, node->right, targetSum, sum);
        
        }
        
        sum-=node->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;

        if(!root) return ans;
        
        dfs(ans, temp, root, targetSum, 0);

        return ans;
    }
};