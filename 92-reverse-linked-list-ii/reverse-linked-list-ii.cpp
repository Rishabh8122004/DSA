class Solution {
public:
    void reverse_using_recursion(ListNode* head,ListNode* &h){
       if(head == NULL)return;
       reverse_using_recursion(head->next,h);
       head->next = NULL;
       h->next = head;
       h = h->next;
       return;
    }
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if((l == r) ||(head == NULL)||(head->next == NULL)) return head;
        ListNode* a = NULL,*b = NULL,*c = NULL,*d = NULL,*t = head;
        int n = 1;
        while(t){
            if(n == l-1){a = t;}
            else if( n == l)b = t;
            else if( n == r)c = t;
            else if( n == r+1)d = t;
            n++;
            t = t->next;
        }
        if(a)a->next = NULL;
        c->next = NULL;
        ListNode* ans = new ListNode(0);
        ListNode* h = ans;
        reverse_using_recursion(b,h);
        if(a)a->next = ans->next;
        b->next = d;
        if(a == NULL)return ans->next;
        return head;
    }
};