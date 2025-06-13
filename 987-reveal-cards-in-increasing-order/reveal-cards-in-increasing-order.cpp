class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& d) {
        int n = d.size();
        sort(d.begin(),d.end());
        vector<int>v(n);
        queue<int>q,idx;
        for(int i = 0;i<n;i++){q.push(d[i]);idx.push(i);}
        while(!q.empty()){
            v[idx.front()] = q.front();
            q.pop();
            idx.pop();
            idx.push(idx.front());
            idx.pop();
        }
        return v;
    }
};