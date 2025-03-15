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
    ListNode* middleNode(ListNode* head) {
        int x = 1;
        ListNode*temp = head;
        ListNode* ans = head;
        bool f = false;
        while(temp){
            temp = temp->next;
            if(f) ans = ans->next;
            f = !f;
        }
        return ans;
    }
};