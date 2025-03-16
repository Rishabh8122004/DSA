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
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        int l1 = 0,l2 = 0;
        ListNode* t = A;
        ListNode* v = B;
        while(t->next || v->next){
            if(t->next){
            t = t->next;
            l1++;
            }
            if(v->next){
            v = v->next;
            l2++;
            }
        }
        t = A;
        v = B;
        while(l1>l2){
            t= t->next;
            l1--;
        }
        while(l2>l1){
            v = v->next;
            l2--;
        }
        while(t->next && v->next){
            if(t == v){break;}
            t = t->next;
            v = v->next;
        }
        if(t==v)return t;
        return NULL;
    }
};