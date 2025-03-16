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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* front = head;
        ListNode* back = head;
        if(front->next == NULL){return NULL;}
        while(front->next->next){
            front = front->next->next;
            back = back->next;
            if(front->next == NULL){back->val = back->next->val;back->next = back->next->next;return head;}
        }
        back->next = back->next->next;
        return head;
    }
};