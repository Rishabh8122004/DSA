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
        if(s->next == NULL){return s->val == head->val;} // if s is the last node, returning if it's equal to first node or not
        if(checking_using_recursion(s->next,head)){
            head = head->next; // if yes, moving head forward for checking if it's equal to current node or not
        }
        else return false; 
        return s->val == head->val; // returning if values are equal or not
    }
    bool isPalindrome(ListNode* head) {
        ListNode* s = head,*f = head;
        while(f && f->next){
            f = f->next;
            s = s->next;
            if(f == NULL)break;
            f = f->next;
        }
        //now, s is the right middle node. or the first node of the second half
        return checking_using_recursion(s,head);
    }
};