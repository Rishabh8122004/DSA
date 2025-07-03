class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>>pq;
        for(int i = 0;i<points.size();i++){
            double dis = sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1]));
            pq.push({dis,i});
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};