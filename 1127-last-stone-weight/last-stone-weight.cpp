class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        priority_queue<int>pq;
        while(stones.size()>1){
            int x = stones.back();
            stones.pop_back();
            int y = stones.back();
            stones.pop_back();
            int temp = x;
            x = min(y,x);
            y = max(y,temp);
            if(x != y){
                stones.push_back(y-x);
            }
            else continue;
            sort(stones.begin(),stones.end());
        }
        if(stones.empty())return 0;
        return stones[0];
    }
};