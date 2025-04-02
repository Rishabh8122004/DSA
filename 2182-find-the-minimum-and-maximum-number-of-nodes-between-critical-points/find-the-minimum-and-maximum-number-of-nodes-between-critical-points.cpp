class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>v;
        ListNode*t = head;
        while(t){
            v.push_back(t->val);
            t = t->next;
        }
        vector<int>d;
        for(int i = 1;i<v.size()-1;i++){
            if((v[i]<v[i-1] && v[i]<v[i+1]) || (v[i]>v[i-1] && v[i]>v[i+1])){d.push_back(i);}
        }
        if(d.size()<2){return {-1,-1};}
        int mm = INT_MAX;
        int mx = d[d.size()-1]-d[0];
        for(int i = 0;i<d.size()-1;i++){
            if(d[i+1]-d[i]<mm){mm = d[i+1]-d[i];}
        }
        return {mm,mx};
    }
};