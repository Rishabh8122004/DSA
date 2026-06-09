class Solution {
public:
    queue<vector<int>> q;
    map<vector<int>, int> mp;
    int op; // number of operation till now..
    int solve(vector<int>& n2, int& n) {
       while(!q.empty()){ 
        auto v = q.front();
        q.pop();
        op = mp[v]; // number of operation till now..
        if (v == n2) {
            return op;
        }
        for (int i = 0; i < v.size(); i++) {
            for (int j = i; j < v.size(); j++) {
                vector<int> block, rem, next;
                for (int k = i; k <= j; k++)
                    block.push_back(v[k]); // getting the block of the vector

                // getting them remaining portion of the vector
                for (int k = 0; k < i; k++)
                    rem.push_back(v[k]); // prefix portion
                for (int k = j + 1; k < n; k++)
                    rem.push_back(v[k]); // suffix portion

                // now inserting the block at every possible position in the
                // remaining vector

                // inserting at the front
                next = block;
                for (int k = 0; k < rem.size(); k++)
                    next.push_back(rem[k]);
                if (mp.count(next) == 0) {
                    q.push(next);
                    mp[next] = op + 1;
                }
                // inserting in the middle
                int k = 0;
                while (k < rem.size()) {
                    next = {};
                    for (int l = 0; l <= k; l++) {
                        next.push_back(rem[l]);
                    }
                    for (int l = 0; l < block.size(); l++)
                        next.push_back(block[l]);
                    for (int l = k + 1; l < rem.size(); l++) {
                        next.push_back(rem[l]);
                    }
                    if (mp.count(next) == 0) {
                        q.push(next);
                        mp[next] = op + 1;
                    }
                    k++;
                }

                // inserting at the end

                next = {};
                next = rem;
                for(int k = 0;k<block.size();k++){
                    next.push_back(block[k]);
                }
                if (mp.count(next) == 0) {
                        q.push(next);
                        mp[next] = op + 1;
                }
            }
        }
    }
        return 1;
    }
    int minSplitMerge(vector<int>& n1, vector<int>& n2) {
        int n = n1.size();
        mp[n1] = 0;
        q.push(n1);
        return solve(n2, n); // n2 vector, size
    }
};