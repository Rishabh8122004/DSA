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
        while(temp->next!=NULL){
            temp = temp->next;
            x++;
        }
        x = (x%2 == 0?(x/2)+1 : (x+1)/2);
        temp = head;
        while(x>1){
            temp = temp->next;
            x--;
        }
        return temp;
    }
};