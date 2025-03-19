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
    ListNode* partition(ListNode* head, int x) {
        ListNode *t = head;
        ListNode* lo = new ListNode(0);
        ListNode* hi = new ListNode(0);
        ListNode* tl = lo;
        ListNode* th = hi;
        while(t){
            if(t->val<x){
                tl->next = t;
                tl = tl->next;
            }
            else{
            th->next = t;
            th = th->next;
            }
            t = t->next;
        }
        lo = lo->next;
        hi = hi->next;
        tl->next = hi;
        th->next = NULL;
        if(lo == NULL)return hi;
        return lo;
    }
};