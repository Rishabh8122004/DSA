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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 1;
        ListNode*temp = head;
        if(temp == NULL)return head;
        while(temp->next){
            temp = temp->next;
            n++;
        }
        temp->next = head;
        k%=n;
        n = n-1-k;
        k = 0;
        temp = head;
        while(k<n){
            temp = temp->next;
            k++;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};