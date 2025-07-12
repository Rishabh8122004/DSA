class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int>q; // max
        priority_queue<int,vector<int>,greater<int>>p; // min
        for(int i = 0;i<nums1.size();i++){
            p.push(nums1[i]);
            if(q.size()<p.size()){
                q.push(p.top());
                p.pop();
            }
            while(q.top()>p.top()){
                int x = q.top();
                q.pop();
                q.push(p.top());
                p.pop();
                p.push(x);
            }
        }
        for(int i = 0;i<nums2.size();i++){
            p.push(nums2[i]);
            if(q.size()<p.size()){
                q.push(p.top());
                p.pop();
            }
            while(q.top()>p.top()){
                int x = q.top();
                q.pop();
                q.push(p.top());
                p.pop();
                p.push(x);
            }
        }
        if(p.size() == q.size()){
            return (p.top()+q.top())/2.0;
        }
        return q.top();
    }
};