class Solution {
public: 
    void solve(ListNode* &t,stack<int> &n,int &rem){
        if(!t){return;}
        n.push(t->val);
        solve(t->next,n,rem);
        n.top()*=2;
        n.top()+=rem;
        t->val = (n.top()%10);
        rem = (n.top()/10);
        n.pop();
        if(rem!=0 && n.size()==0)n.push(rem);
        return;
    }
    ListNode* doubleIt(ListNode* head) {
        stack<int> n;
        ListNode* t = head;
        int rem = 0;//remainder
        solve(t,n,rem);
        while(n.size()){
            ListNode* dummy = new ListNode(n.top());
            dummy->next = head;
            head = dummy;
            n.pop();
        }
        return head;
    }
};