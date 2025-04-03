/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node *b = head,*f = (b)?head->next:NULL;
        while(b){
            if(b->child!=NULL){
                b->next = b->child;
                b->child->prev = b;
                Node *t = b->child;
                while(t->next){
                    t = t->next;
                }
                t->next = f;
                if(f)f->prev = t;
                f = b->next;
            }
            b = b->next;
            if(f)f = f->next;
        }
        b = head;
        while(b){
           b->child = NULL;
           b = b->next;
        }
        return head;
    }
};