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
    vector<int> preorderTraversal(TreeNode* root) {
        //morris traversal

        vector<int>ans;

        TreeNode* curr = root;

        while(curr){
            if(curr->left){
                TreeNode * temp = curr->left;
                while(temp->right!=NULL) temp = temp->right;

                temp->right = curr->right;
                curr->right = curr->left;
                curr->left  = NULL;
            }
            ans.push_back(curr->val);
            curr = curr->right;
        }

        return ans;
    }
};