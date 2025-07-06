class Solution {
public: 
    void solve(ListNode* &t,int n,int &rem){
        if(!t){return;}
        n=t->val;
        solve(t->next,n,rem);
        n*=2;
        n+=rem;
        t->val = (n%10);
        rem = (n/10);
        return;
    }
    ListNode* doubleIt(ListNode* head) {
        int n;
        ListNode* t = head;
        int rem = 0;//remainder
        solve(t,n,rem);
        if(rem!=0){
            ListNode* dummy = new ListNode(rem);
            dummy->next = head;
            head = dummy;
        }
        return head;
    }
};