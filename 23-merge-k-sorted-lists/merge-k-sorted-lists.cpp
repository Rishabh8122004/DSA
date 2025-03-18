class Solution {
public:
    ListNode* sortlists(ListNode* a,ListNode* b){
        if(a == NULL && b == NULL)return NULL;
        else if(a == NULL){return b;}
        else if(b == NULL)return a;
        ListNode* c;
        if(a->val<=b->val){
            c = a;
            if(a)a = a->next;
        }
        else{
            c = b;
            if(b)b = b->next;
        }
        ListNode* head = c;
        while(a || b){
            if(a == NULL){c->next = b;return head;}
            if(b == NULL){c->next = a;return head;}
            if(a->val<=b->val){
            c->next = a;
            if(a)a = a->next;
            c = c->next;
            }
            else{
                c->next = b;
                if(b)b = b->next;
                c = c->next;
            }
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode* ans;
        while(lists.size()>1){
            ListNode* a = lists[0];
            lists.erase(lists.begin());
            ListNode* b = lists[0];
            lists.erase(lists.begin());
            ans = sortlists(a,b);
            lists.push_back(ans);
        }
        return lists[0];
    }
};