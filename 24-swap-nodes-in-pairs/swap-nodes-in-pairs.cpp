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
    ListNode* swap(ListNode* a,ListNode* b,ListNode* c){
        if(!c || !c->next){
            b->next = a;
            a->next = c;
            return b;
        }
        b->next = a;
        a->next = swap(c,c->next,(c->next?c->next->next:c->next));
        return b;
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        head =  swap(head,head->next,head->next->next);
        return head;
    }
};