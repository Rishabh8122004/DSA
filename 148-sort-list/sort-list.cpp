class Solution {
public:
    ListNode* merge(ListNode* a,ListNode*b){
        ListNode* ans;
        if(a == NULL) return b;
        if(b == NULL) return a;
        if(a->val <= b->val){
            ans = a;
            if(a) a = a->next;
        }
        else{
            ans = b;
            if(b)b = b->next;
        }
        ListNode* head = ans;
        while(a || b){
            if(a == NULL){ans->next = b;return head;}
            if(b == NULL){ans->next = a;return head;}
            if(a->val <= b->val){
            ans->next = a;
            ans = ans->next;
            if(a) a = a->next;
        }
        else{
            ans->next = b;
            ans = ans->next;
            if(b)b = b->next;
        }
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        // calculating middle of the linked list for breaking it into two parts, so that we can apply merge sort
        ListNode* slow = head;
        ListNode* fast = head;
        // calculating left middle -> fast->next->next and for right - > fast->next
        //  odd length list   even length list
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        } 
        //now our slow is at left middle , we gonna break the list into two parts
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        slow = sortList(slow);
        fast = sortList(fast);
        head = merge(slow,fast);
        return head;
    }
};