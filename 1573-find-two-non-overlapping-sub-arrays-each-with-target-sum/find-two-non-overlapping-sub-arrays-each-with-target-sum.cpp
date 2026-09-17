class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int t) {
        int n = arr.size();
        vector<int> pref(n,INT_MAX), suff(n,INT_MAX);
        int s = 0;
        int i = 0, j = 0;
        int l = INT_MAX;
        while (j < n) {
            s += arr[j];
            pref[j] = l;
            while ((s >= t)) {
                if (s == t) {
                    l = min(l,(j - i + 1)); // storing the minimum length of the subarray having sum = t starting at i
                }
                s -= arr[i];
                i++;
            }
            j++;
        }
        i = n-1;j = n-1;l = INT_MAX;
        s = 0;
        while(j>=0){
            s+=arr[j];
            while(s >= t){
                if(s == t){
                    l = min(l,(i-j+1));
                }
                s-=arr[i];
                i--;
            }
            suff[j] = l;
            j--;
        }
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            if(pref[i] == INT_MAX || suff[i] == INT_MAX)continue;
            ans = min(pref[i]+suff[i],ans);
        }
        return ans == INT_MAX?-1:ans;
    }
};