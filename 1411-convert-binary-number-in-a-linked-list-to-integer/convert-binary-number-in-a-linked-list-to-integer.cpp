class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int x = 0,a = 1;
        vector<int>v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        for(int i = v.size()-1;i>=0;i--){
            if(v[i] == 1){
                x+=a;
            }
            a*=2;
        }
        return x;
    }
};