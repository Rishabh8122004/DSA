class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* t = head;
        int n = 0;
        while(t){
            t = t->next;
            n++;
        }
        int x = n/k;
        int y = n%k;
        if(x == 0){x = 1;y = 0;}
        t = head;
        vector<ListNode*>v;
        int s = x;
        while(k--){
            ListNode* h = new ListNode(0);
            ListNode* i = h;
            x = s;
            if(t){
            while(x--){
                i->next = t;
                t = t->next;
                i = i->next;
            }
            if(y>0){
                i->next = t;
                t = t->next;
                i = i->next;
                y--;
            }
            i->next = NULL;
            }
            h = h->next;
            v.push_back(h);
        }
        return v;
    }
};