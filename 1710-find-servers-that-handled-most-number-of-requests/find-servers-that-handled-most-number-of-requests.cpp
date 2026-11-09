class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> st;
        for (int i = 0; i < k; i++) {
            st.insert(i);
        }
        vector<int>count(k,0); // this will count the no. of request handled by each server
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy_server; // this will tell which server is free earliest

        for (int i = 0; i < arrival.size(); i++) {
            while (!busy_server.empty() && (busy_server.top().first <= arrival[i])) { // excluding the server that are free now
                st.insert(busy_server.top().second);
                busy_server.pop();
            }
            if(st.empty())continue; // No server available ,  just drop the request

            set<int>::iterator it = st.lower_bound((i % k)); // finding correct server either (i%k) or bigger 

            if (it == st.end()) { // no bigger/next server is available
                it = st.begin();
            }

            busy_server.push({arrival[i] + load[i] , *it});
            count[*it]++;
            st.erase(*it);
        }
        int mx = count[0];
        for(int i = 0;i<k;i++){
            mx = max(mx,count[i]);
        }
        vector<int>ans;
        for(int i = 0;i<k;i++){
            if(count[i] == mx)ans.push_back(i);
        }
        return ans;
    }
};