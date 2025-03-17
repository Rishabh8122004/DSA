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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)return list2;
        if(list2 == NULL)return list1;
        ListNode* a;
        if(list1->val<=list2->val){a = list1;list1 = list1->next;}
        else {a = list2;list2 = list2->next;}
        ListNode* head = a;
        if(list1 == NULL){a->next = list2;return head;}
        if(list2 == NULL){a->next = list1;return head;}
        while(list1 && list2){
            if(list1->val<=list2->val){
                a->next = list1;
                a = a->next;
                if(list1->next == NULL){a->next = list2;return head;}
                list1 = list1->next;
            }
            else{
                a->next = list2;
                a = a->next;
                if(list2->next == NULL){a->next = list1;return head;}
                list2 = list2->next;
            }
        }
        return head;
    }
};