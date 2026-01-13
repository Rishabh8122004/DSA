class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if(arr[n-1]-n < k)return (arr[n-1]+(k-(arr[n-1]-n))); // last element - missing elements before last
        int lo = 0,hi = n-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(arr[mid]-(mid+1) >= k)hi = mid-1;
            else lo = mid+1;
        }
        if(hi < 0)return k;
        return arr[hi]+(k-(arr[hi]-(hi+1)));
    }
};