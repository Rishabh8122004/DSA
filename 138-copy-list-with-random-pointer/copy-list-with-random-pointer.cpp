class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node* copiedHead = new Node(head->val);
        Node *t = head, *temp = copiedHead;
        t = t->next;
        while (t) {
            Node* a = new Node(t->val);
            temp->next = a;
            temp = temp->next;
            t = t->next;
        }
        unordered_map<Node*, Node*> mp;
        t = copiedHead;
        temp = head;
        while (t) {
            mp.insert({temp, t});
            t = t->next;
            temp = temp->next;
        }
        t = head;
        temp = copiedHead;
        while (t) {
            if (t->random) {
                temp->random = mp[t->random];
            }
            t = t->next;
            temp = temp->next;
        }
        return copiedHead;
    }
};
