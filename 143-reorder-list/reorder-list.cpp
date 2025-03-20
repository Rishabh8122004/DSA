class Solution {
public:
    void reverse(ListNode* head,ListNode* & second){
        if(head == NULL){return;}
        reverse(head->next,second);
        head->next = NULL;
        second->next = head;
        second = second->next;
        return;
    }
    void reorderList(ListNode* head) {
        //finding left middle 
        ListNode *s =head, *f = head;
        while(f->next && f->next->next){
            f = f->next;
            s = s->next;
            if(f)f = f->next;
        }
        ListNode *end = s; // making it as end;
        s = s->next; // moving s ot right middle so that we can reverse the second half
        end->next = NULL; // ending the first half
        ListNode* second = new ListNode(0); // storing the reverse of second half behind the 'second' node
        ListNode* temp = second;
        reverse(s,temp);
        second = second->next;
        f = head; // to iterate the first half and adding the reversed second half of the lest alternatively
        ListNode* t = new ListNode(0);
        ListNode *ta = head,*tb = second,*tc = t;
        while(ta || tb){
            tc->next = ta;
            if(ta)ta = ta->next;tc = tc->next;
            tc->next = tb;
            if(tb)tb = tb->next;tc = tc->next;
        }
        head = t->next;
        return;
    }
};