class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        if(k == 1)return v;
        int n = v.size();
        deque<int>q;
        q.push_back(v[0]);
        for(int i = 1;i<k;i++){
            while(!q.empty() && v[i]>q.back()){q.pop_back();}
            q.push_back(v[i]);
        }
        vector<int>ans;
        int i = 0,j = k-1;
        while(i<n-k+1){
            ans.push_back(q.front());
            if(v[i] == q.front())q.pop_front();
            i++;j++;
            if(j>=n)break;
            while(!q.empty() && v[j]>q.back()){
                q.pop_back();
            }
            q.push_back(v[j]);
        }
        return ans;
    }
};