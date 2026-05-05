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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        
        TreeNode* temp = root;

        while(temp){
            if(temp->val==val) return root;

            else if(temp->val<val){
                if(temp->right==NULL){
                    TreeNode* x = new TreeNode(val);
                    temp->right = x;
                }

                temp = temp->right;
            }
            else{
               if(temp->left==NULL){
                    TreeNode* x = new TreeNode(val);
                    temp->left = x;
                }

                temp = temp->left; 
            }
        }

        return root;
    }
};