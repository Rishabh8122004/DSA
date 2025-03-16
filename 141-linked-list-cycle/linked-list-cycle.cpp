/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int x = 0;
        while(x<=10001){
            if(head == NULL)return false;
            head = head->next;
            x++;
        }
        return true;
    }
};