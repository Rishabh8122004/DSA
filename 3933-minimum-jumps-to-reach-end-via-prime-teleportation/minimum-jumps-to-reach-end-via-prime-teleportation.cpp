class Solution {
public:
    bool is_prime(int x) {
        if (x <= 1)
            return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }
    void fill_factors(int idx, int x, unordered_map<int, vector<int>>& mp) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                if (mp.find(i) != mp.end()) {
                    mp[i].push_back(idx);
                }
                if ((i != x / i) && (mp.find(x / i) != mp.end())) {
                    mp[x / i].push_back(idx);
                }
            }
        }
        return;
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            if (is_prime(nums[i])) {
                mp[nums[i]].push_back(i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) == mp.end()) { // not a prime number
                fill_factors(i, nums[i], mp);
            }
        }
        vector<int>vis(n,0); // is the indexed is already visited or not
        queue<int>q;
        int jump = 0;//initially at index 0
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){ // traversing the current level only...
                int x = q.front();
                if(x == n-1)return jump;
                q.pop();
                if(mp.find(nums[x]) != mp.end()){ // prime number that exists in nums
                    for(auto nxt:mp[nums[x]]){
                        if(nxt == n-1)return jump+1;
                        if(!vis[nxt]){vis[nxt] = 1; q.push(nxt);}
                    }
                    mp[nums[x]].clear();
                }
                if(x-1>=0 && !vis[x-1]){vis[x-1] = 1; q.push(x-1);}
                if(x+1 < n && !vis[x+1]){vis[x+1] = 1; q.push(x+1);}
                if(x+1 == n-1)return jump+1;
            }
            jump++;
        }
        return jump;
    }
};