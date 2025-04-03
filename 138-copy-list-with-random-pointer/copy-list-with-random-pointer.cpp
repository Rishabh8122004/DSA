class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        Node* main = head;

        // Step 1: Insert copied nodes next to original nodes
        while (head) {
            Node* temp = new Node(head->val);
            temp->next = head->next;
            head->next = temp;
            head = temp->next;
        }

        // Step 2: Assign random pointers to copied nodes
        head = main;
        while (head) {
            if (head->random) {
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }

        // Step 3: Separate original and copied list
        head = main;
        Node* copiedHead = head->next;
        Node* copied = copiedHead;

        while (head) {
            head->next = copied->next;
            head = head->next;
            if (head) {
                copied->next = head->next;
                copied = copied->next;
            }
        }

        return copiedHead;
    }
};
