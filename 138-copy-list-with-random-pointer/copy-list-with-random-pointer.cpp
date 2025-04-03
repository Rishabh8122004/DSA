/*
Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* main = head;
        if(head == NULL)return head;
        Node* h = new Node(0);
        Node*t = h;
        int n = 1;
        while(head){  
            Node* temp1 = new Node(0),*temp2 = new Node(0);
            temp1->val = head->val;
            if(head->next)temp2->val = head->next->val;
            t->val = temp1->val;
            if(head->next)t->next = temp2;
            t = t->next;
            head = head->next;
            n++;
        }
        Node* p = main;
        Node* q = h;
        while(p){
            Node* a = main,*b = h;
            int j = 0;
            while(a!=p->random && a){
                a = a->next;
                b = b->next;
                j++;
            }
            if(p->random)q->random = b;
            p = p->next;
            q = q->next;
        }
        return h;
    }
};