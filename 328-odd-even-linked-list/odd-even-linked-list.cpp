class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        bool f = true; // true for odd index, else even
        ListNode *odd = new ListNode(0),*even = new ListNode(0),*to = odd,*te = even;
        while(head){
            if(f){
                to->next = head;
                to = to->next;
            }
            else{
                te->next = head;
                te = te->next;
            }
            f = !f;
            head = head->next;
        }
        even = even->next;
        odd = odd->next;
        to->next = even;
        te->next = NULL;
        return odd;
    }
};