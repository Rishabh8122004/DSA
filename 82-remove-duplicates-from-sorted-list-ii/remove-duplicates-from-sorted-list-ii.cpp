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
    ListNode* deleteDuplicates(ListNode* h) {
        if(!h || !h->next)return h;
        ListNode* curr = h,*prev;
        ListNode* nxt = h->next;
        int x = -200;
        while(curr){
            if(curr->val == nxt->val){
                x = curr->val;
            }
            while(curr && curr->val == x){
                curr = curr->next;
            }
            if(!curr){return NULL;}
            nxt = curr->next;
            if(!nxt || (curr->val != nxt->val)){
                h = curr;
                break;
            }
        }
        prev = h;
        curr = h->next;
        // now we have a valid head
        // we gonna add the upcoming valid nodes
        while(curr){
            nxt = curr->next;
            if(!nxt)break;
            if(curr->val == nxt->val){
                x = curr->val;
            }
            while(curr && curr->val == x){
                curr = curr->next;
            }
            if(!curr){prev->next = curr; break;}
            nxt = curr->next;
            if(!nxt || (curr->val != nxt->val)){
                prev->next = curr;
                prev = prev->next;
                if(curr)curr = curr->next;
            }
        }
        return h;
    }
};