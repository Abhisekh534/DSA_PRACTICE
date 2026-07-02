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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>>mp;

        stack<pair<TreeNode*, pair<int, int>>>st;

        st.push({root, {0, 0}});

        while(!st.empty()){
            TreeNode* node = st.top().first;
            int x = st.top().second.first;
            int y = st.top().second.second;

            mp[x][y].push_back(node->val);
            st.pop();

            if(node->left){
                st.push({node->left, {x-1, y+1}});
            }
            if(node->right){
                st.push({node->right, {x+1, y+1}});
            }
        }

        vector<vector<int>>ans;

        for(auto&x : mp){
            vector<int>temp;
            for(auto&y : x.second){
                sort(y.second.begin(), y.second.end());
                for(int z : y.second){
                    temp.push_back(z);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};