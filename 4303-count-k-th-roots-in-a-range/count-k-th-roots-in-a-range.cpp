class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1)return r-l+1;
        int ans = 0, lo = 0, hi;
        int x = 0;
        while(pow(x,k)<l)x++;
        l = pow(x,k);
        while (l <= r) {
            hi = l;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (pow(mid, k) == l) {
                    ans++;
                    l = pow(mid+1,k)-1;
                    break;
                } else if (pow(mid, k) < l) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            l++;
        }
        return ans;
    }
};