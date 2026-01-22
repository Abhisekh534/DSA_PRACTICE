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
    int solve(TreeNode* root){
        if(!root) return 0;
        
        int lh = 0, rh=0;
        
        TreeNode* temp = root;
        while(temp){
            lh++;
            temp = temp->left;
        }

        temp = root;
        while(temp){
            rh++;
            temp = temp->right;
        }

        if(lh==rh) return pow(2, lh) - 1;
        else return 1 + solve(root->left) + solve(root->right);
    }
    int countNodes(TreeNode* root) {
        return solve(root);
    }
};