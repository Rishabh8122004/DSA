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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while(l1 || l2){
            int t = 0;
            if(l1){t+=l1->val;l1 = l1->next;}
            if(l2){t+=l2->val;l2 = l2->next;}
            temp->val += t;
            if(l1||l2||temp->val > 9)temp->next = new ListNode(0);
            if(temp->val > 9){
                temp->next->val = 1;
                temp->val = (temp->val%10);
            }
            temp = temp->next;
        }
        return head;
    }
};