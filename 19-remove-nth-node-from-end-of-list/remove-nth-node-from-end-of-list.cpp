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
        ListNode* front = head;
        ListNode* back = head;
        int y = 1,x = 1;
        while(front->next){ // again using two pointers and maintaining the distance of n
            front = front->next;
            y++;
            while(y-x > n){ // if distance exceed moving the back pointer
            back = back->next;
            x++;
            }
        }
        if(y == n)return head->next;
        back->next = back->next->next;
        return head;
    }
};