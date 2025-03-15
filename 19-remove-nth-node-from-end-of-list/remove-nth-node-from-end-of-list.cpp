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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* ans = head;
        int y = 1,x = 1;
        while(temp->next){
            temp = temp->next;
            y++;
        }
        if(y == n)return head->next;
        while(y-x > n){
            ans = ans->next;
            x++;
        }
        ans->next = ans->next->next;
        return head;
    }
};