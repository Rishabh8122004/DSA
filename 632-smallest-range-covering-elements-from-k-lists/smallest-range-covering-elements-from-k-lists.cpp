class Solution {
public:
    typedef pair<int,pair<int,int>> pip; // num,row,col
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pip,vector<pip>,greater<pip>>pq;
        int mx = nums[0][0];
        int start,end;
        for(int i = 0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
            mx = max(mx,nums[i][0]);
        }
        start = pq.top().first;
        end = mx;
        int r = pq.top().second.first; // row of minimum element in heap
        int c = pq.top().second.second;// col of minimum element in heap
        while(c < nums[r].size()-1){
            pq.pop();
            pq.push({nums[r][c+1],{r,c+1}});
            mx = max(mx,nums[r][c+1]);
            if((end-start) > (mx-pq.top().first)){
                start = pq.top().first;
                end = mx;
            }
            r = pq.top().second.first; // row of minimum element in heap
            c = pq.top().second.second;// col of minimum element in heap
        }
        return {start,end};
    }
};