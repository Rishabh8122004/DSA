class Solution {
public:
    ListNode* sortlist(ListNode* a,ListNode* b){
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
        if(lists.size() == 0)return NULL;
        ListNode* ans = lists[0];
        int j = 1;
        while(j<lists.size()){
            ans = sortlist(ans,lists[j]);
            j++;
        }
        return ans;
    }
};