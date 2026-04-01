class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& a, string d) {
        int n = p.size();

        // Convert left-moving robots to negative health
        for(int i = 0; i < n; i++){
            if(d[i] == 'L') a[i] = -1 * a[i];
        }

        // Store {position, health}
        vector<vector<int>> v(n, vector<int>(2));
        for(int i = 0; i < n; i++){
            v[i][0] = p[i];
            v[i][1] = a[i];
        }

        // Sort by position
        sort(v.begin(), v.end());

        stack<int> st;
        st.push(0); // first robot index

        int j = 1, x, y, i;

        while (j < n) {

            // Push all right-moving robots
            while(j < n && v[j][1] > 0){
                st.push(j);
                j++;
            }

            if(j == n) break;

            i = st.top();
            x = v[i][1];
            y = v[j][1];

            // Handle collisions
            while (j < n && !st.empty() && (x > 0 && y < 0)) {

                if (x == abs(y)) {
                    // both destroyed
                    st.pop();
                    j++;
                } 
                else if (x < abs(y)) {
                    // left robot stronger
                    st.pop();
                    v[j][1] += (v[j][1] < 0 ? 1 : -1);
                } 
                else {
                    // right robot stronger
                    j++;
                    v[i][1] += (v[i][1] < 0 ? 1 : -1);
                }

                if(st.empty() || j == n) break;

                // update current values
                i = st.top();
                x = v[i][1];
                y = v[j][1];
            }

            if(j == n) break;

            // push remaining robot
            st.push(j);
            j++;
        }

        // store survivors (position → health)
        map<int,int> mp;
        while(st.size()){
            mp[v[st.top()][0]] = v[st.top()][1];
            st.pop();
        }

        // build answer in original order
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(mp.find(p[i]) != mp.end()){
                ans.push_back(abs(mp[p[i]]));
            }
        }

        return ans;
    }
};