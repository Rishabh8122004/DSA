class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (!head)
            return head;

        while (true) {
            vector<ListNode*> v;
            ListNode* t = head;
            while (t) {
                v.push_back(t);
                t = t->next;
            }

            bool removed = false;
            for (int i = 0; i < v.size(); ++i) {
                int sum = 0;
                for (int j = i; j < v.size(); ++j) {
                    sum += v[j]->val;
                    if (sum == 0) {
                        if (i == 0) {
                            head = (j + 1 < v.size()) ? v[j + 1] : nullptr;
                        } else {
                            v[i - 1]->next =
                                (j + 1 < v.size()) ? v[j + 1] : nullptr;
                        }
                        removed = true;
                        break;
                    }
                }
                if (removed)
                    break;
            }

            if (!removed)
                break;
        }

        return head;
    }
};
