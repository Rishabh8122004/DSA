class Solution {
public:
    typedef pair<double,pair<int,int>> pip;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pip>pq; // which stores the maximum of all fractions , arr[i],arr[j]
        int j = arr.size()-1;
        int i = 0;
        while(j>0){
            pq.push({((double)arr[i]/arr[j]),{arr[i],arr[j]}});
            i++;
            while(pq.size()>k)pq.pop();
            if(i == j){i = 0;j--;}
        }
        return {pq.top().second.first,pq.top().second.second};
    }
};