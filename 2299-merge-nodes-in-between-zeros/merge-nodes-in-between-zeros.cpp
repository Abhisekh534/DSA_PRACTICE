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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode*temp = head;

        while(temp){

            ListNode* pre = temp;
            temp = temp->next;
            int sum = 0;
            while(temp && temp->val!=0){
                sum+=temp->val;
                temp = temp->next;
            }
            pre->val = sum;
            if(temp==NULL || temp->next==NULL) pre->next = NULL;
            else pre->next = temp;
                
        }

        return head;
    }
};