class Solution {
public:
    int get_val( vector<long long>& pos,int idx,int target){
        int n = pos.size()/2;
        int lo = idx+1,hi = idx + n;
        int ans = idx+n;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(pos[mid] >= target){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
    bool is_valid(int& mid, vector<long long>& pos, int& k, long long& per) {
        int n = pos.size() / 2;

        // try each starting point
        for (int i = 0; i < n; i++) {
            int count = 1;
            long long last = pos[i];
            int idx = i;
            for(int j = 2;j<=k;j++){
                long long target = last + mid;
                auto it = lower_bound(begin(pos) + idx + 1,begin(pos) + i + n,target);
                if(it == begin(pos) + i + n) break;
                idx = it-begin(pos);
                last = pos[idx];
                count++;
            }
            // check circular condition
            if (count == k && (pos[i] + per - last) >= mid) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;

        // map (x,y) → 1D perimeter position
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            if (x == 0)
                pos.push_back(y); // left
            else if (y == side)
                pos.push_back(side + x); // top
            else if (x == side)
                pos.push_back(3LL * side - y); // right
            else
                pos.push_back(4LL * side - x); // bottom
        }

        sort(pos.begin(), pos.end());

        int n = pos.size();
        long long per = 4LL * side;

        // duplicate for circular handling
        for (int i = 0; i < n; i++) {
            pos.push_back(pos[i] + per);
        }

        int lo = 0, hi = 2 * side, ans = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (is_valid(mid, pos, k, per)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};