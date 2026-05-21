class Solution {
public:
    bool isPossible(vector<int>& t) {
        int n = t.size();
        if(n == 1 && t[0] != 1)return false;
        long long sum = 0;
        priority_queue<int>pq;
        for(int i = 0;i<t.size();i++){sum += t[i]; pq.push(t[i]);}
        while(pq.top()!=1){
            int x = pq.top();
            pq.pop();
            sum-=x;
            if(sum == 1)return true;
            if(x <= sum || sum == 0)return false;
            pq.push(x%sum);
            if(x%sum == 0)return false;
            sum += x%sum;
        }
        return true;
    }
};