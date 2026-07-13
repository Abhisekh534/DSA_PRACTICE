/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        deque<Node*>q;

        q.push_back(root);

        while(!q.empty()){
            int s = q.size();
            bool first = true;
            while(s--){
                Node* node = q.front();
                q.pop_front();
                
                if(node->left){
                    if(!first){
                        q.back()->next = node->left;
                    }else first = false;
        
                    q.push_back(node->left);
                }
                if(node->right){
                    if(!first){
                        q.back()->next = node->right;
                    }else first = false;
        
                    q.push_back(node->right);
                }
            }
        }

        return root;
    }
};