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
    void reverse(ListNode* &head,ListNode* &temp){
        temp->next = head;
        ListNode*curr = head->next,*prev = head,*nxt = curr->next;
        while(prev != temp){
            curr -> next = prev;
            prev = curr;
            curr = nxt;
            nxt = curr->next;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int a = k-1;
        ListNode*temp = head;
        while(a-- && temp){
            temp = temp->next;
        }
        if(!temp)return head;
        ListNode* x = temp->next;
        reverse(head,temp);
        head->next = reverseKGroup(x,k);
        return temp;
    }
};