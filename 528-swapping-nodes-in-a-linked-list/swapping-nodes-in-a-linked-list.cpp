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
    ListNode* swapNodes(ListNode* head, int k) {
        int l = 1;
        ListNode *t1,*t2,*temp = head;
        while(temp){
            if(l == k){t1 = temp;}
            temp = temp->next;
            l++;
        }
        temp = head;
        int a = 1;
        while(temp){
            if(a == l-k){t2 = temp;break;}
            temp = temp->next;
            a++;
        }
        swap(t1->val,t2->val);
        return head;
    }
};