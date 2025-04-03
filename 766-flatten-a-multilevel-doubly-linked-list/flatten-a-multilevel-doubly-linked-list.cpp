class Solution {
public:
    Node* flatten(Node* head) {
        // `curr` is used to traverse the main list
        Node *curr = head, *nextNode = (curr) ? head->next : NULL;

        while (curr) {
            // If the current node has a child, we merge it into the main list
            if (curr->child != NULL) {
                curr->next = curr->child;  // Link current node to its child
                curr->child->prev = curr;  // Set child's previous pointer
                
                // Find the last node of the child list
                Node *lastChild = curr->child;
                while (lastChild->next) {
                    lastChild = lastChild->next;
                }

                // Connect last node of the child list to `nextNode`
                lastChild->next = nextNode;
                if (nextNode) nextNode->prev = lastChild;

                // Move `nextNode` to the new next node after merging
                nextNode = curr->next;
            }
            curr->child = NULL; // Flattened list should not have child pointers
            // Move to the next node in the main list
            curr = curr->next;
            if (nextNode) nextNode = nextNode->next;
        }
        return head; // Return the modified flattened list
    }
};