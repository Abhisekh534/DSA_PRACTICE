/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        unordered_map<Node*, Node*>mp;

        Node* headD = new Node(head->val);
        mp[head] = headD;

        Node* temp = head;
        Node* temp2 = headD;

        while(temp->next){
            Node* x = new Node(temp->next->val);
            temp2->next = x;

            temp = temp->next;
            temp2 = temp2->next;
            mp[temp] = temp2;
        }

        temp = head;
        temp2 = headD;

        while(temp){
            temp2->random = mp[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }

        return headD;
    }
};