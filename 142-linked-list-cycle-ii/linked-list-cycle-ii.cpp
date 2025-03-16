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
    ListNode *detectCycle(ListNode *head) {
        ListNode* s = head;
        ListNode* f = head;
        ListNode* fix;
        if(f == NULL)return NULL;
        while(f){
            f = f->next;
            s = s->next;
            if(f == NULL)return NULL;
            f = f->next;
            if(f == s){fix = s;break;}
        }
        if(f == NULL)return NULL;
        f = fix->next;s = head;
        while(s != fix->next){
            while(f!=fix){
                f = f->next;
                if(f == s)return s;
            }
            f = fix->next;
            s = s->next;
        }
        return s;
    }
};