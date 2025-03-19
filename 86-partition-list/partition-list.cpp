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
        ListNode *t = head; // to iterate the main linkedlist
        ListNode* lo = new ListNode(0); // two linked list , one connects smaller nodes
        ListNode* hi = new ListNode(0); // another connects bigger nodes
        ListNode* tl = lo; // to iterate lo linkedlist
        ListNode* th = hi; // to iterate hi linkedlist
        while(t){
            if(t->val<x){ // connecting smaller nodes
                tl->next = t;
                tl = tl->next;
            }
            else{ // connecting greator nodes
            th->next = t;
            th = th->next;
            }
            t = t->next; // iterating through head
        }
        lo = lo->next; // since lo was an extra node , removing it 
        hi = hi->next; // simmilarly removing hi because it was extra
        tl->next = hi; // connecting lo with hi
        th->next = NULL; // connecting hi with null
        if(lo == NULL)return hi; // if there is no smaller element then returning hi
        return lo; // else, returning lo
    }
};