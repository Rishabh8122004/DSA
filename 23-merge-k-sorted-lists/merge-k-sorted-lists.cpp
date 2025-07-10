class Solution {
public:
    typedef pair<int,int> pip; // ListNode->val, row,col
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pip,vector<pip>,greater<pip>>pq;
        for(int i = 0;i<lists.size();i++){
            if(lists[i]) pq.push({lists[i]->val,i});
        }
        if(pq.empty())return NULL;
        int r = pq.top().second;
        ListNode* root = lists[r];
        ListNode* temp = root;
        pq.pop();
        while(!pq.empty()){
            if(lists[r]->next){lists[r] = lists[r]->next; pq.push({lists[r]->val,r});}
            r = pq.top().second;
            temp->next = lists[r];
            temp = temp->next;
            pq.pop();
        }
        return root;
    }
};