class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n);
        v[0] = arr[0];
        int e = 1,o = 0;
        long int ans = 0;
        for(int i = 1;i<n;i++){
            v[i] = arr[i]+v[i-1];
        }
        for(int i = 0;i<n;i++){
            v[i]%2 == 0?e++:o++;
            ans+=(v[i]%2 == 0?o:e);
        }
        return (ans%1000000007);
    }
};