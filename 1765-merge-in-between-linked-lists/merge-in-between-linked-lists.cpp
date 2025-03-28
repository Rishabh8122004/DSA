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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int x = 0;
        ListNode *temp = list1,*t1,*t2,*t3;
        while(x<=b){
            if(x == a-1){t1 = temp;}
            if(x == b){t2 = temp;}
            x++;
            temp = temp->next;
        }
        t1->next = list2;
        temp = list2;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = t2->next;
        return list1;
    }
};