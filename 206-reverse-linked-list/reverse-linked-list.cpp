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
    void reverse_using_recursion(ListNode* head,ListNode* &h){
       if(head == NULL)return;
       reverse_using_recursion(head->next,h);
       head->next = NULL;
       h->next = head;
       h = h->next;
       return;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = new ListNode(0);
        ListNode* h = ans;
        reverse_using_recursion(head,h);
        return ans->next;
    }
};