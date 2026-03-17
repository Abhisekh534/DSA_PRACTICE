/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>>mH;

        for(int i=0; i<lists.size(); i++){
            ListNode* temp = lists[i];

            while(temp){
                mH.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode* head = new ListNode();

        ListNode* temp = head;

        while(!mH.empty()){
            ListNode* nextN = new ListNode();
            temp->next = nextN;
            nextN->val = mH.top();
            mH.pop();
            temp = temp->next;
        }

        return head->next;
    }
};