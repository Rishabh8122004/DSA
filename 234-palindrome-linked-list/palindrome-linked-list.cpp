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
    bool checking_using_recursion(ListNode* s,ListNode* &head){
        if(s->next == NULL){return s->val == head->val;}
        if(checking_using_recursion(s->next,head)){
            head = head->next;
        }
        else return false;
        return s->val == head->val;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* s = head,*f = head;
        while(f && f->next){
            f = f->next;
            s = s->next;
            if(f == NULL)break;
            f = f->next;
        }
        //s is the right middle node, now watch this.
        return checking_using_recursion(s,head);
    }
};