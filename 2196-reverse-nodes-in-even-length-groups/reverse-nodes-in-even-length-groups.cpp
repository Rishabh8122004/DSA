class Solution {
public:
    void reverse(ListNode* h, int x) {
        ListNode* p = h, *c = p->next, *n = (c) ? c->next : nullptr;
        while (x>0 && c) {
            c->next = p;
            p = c;
            c = n;
            if (n) n = n->next;
            x--;
        }
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *p = head, *a = head->next, *b = head->next;
        int x = 2, l = 2, r = 2;
        while (b) {
            while (((r - l + 1) < x) && b->next) {
                b = b->next;
                r++;
            }
            ListNode* f = b->next; // Store next group's start
            if ((r - l + 1) % 2 == 0) p->next = b;
            p = b;
            if ((r - l + 1) % 2 == 0) {
                p = a;
                reverse(a,(r - l));
                a->next = f;
            }
            // Move pointers forward
            a = f;b = f;
            x++;
            r++;
            l = r;
        }
        return head;
    }
};