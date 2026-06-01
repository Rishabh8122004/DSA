class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;
        sort(cost.begin(),cost.end());
        int i = cost.size()-1;
        while(i>=0){
            if(i == 0){ans += cost[i];i--;}
            else if(i>0){ans += cost[i]+cost[i-1];i-=3;}
        }
        return ans;
    }
};