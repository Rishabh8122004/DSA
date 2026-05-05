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
        int n = 0;
        ListNode* t = head,*l;
        while(t){
            if(t->next == NULL)l = t;
            t = t->next;
            n++;
        }
        if(n == 0)return head;
        k = k%n;
        n-=k;
        t = head;
        if(n)l->next = head;
        while(n-1){
            t = t->next;
            n--;
        }
        head = t->next;
        t->next = NULL;
        return head;
    }
};