class Solution {
public:
    vector<int> assignTasks(vector<int>& server, vector<int>& task) {
        int m = task.size(),n = server.size();
        vector<int>ans;
        // free_server will provide minimum weight server on top that are not busy at the second
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>free_server;
        // busy_server will provide the server that is going to be free the earliest
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>>busy_server;
        for(int i = 0;i<server.size();i++){
            free_server.push({server[i],i});
        }
        long long second = 0;
        int j = 0;
        while(j<task.size()){
            second = max(second,(long long)j);
            while((!busy_server.empty()) && (busy_server.top().first <= second)){
                int idx = busy_server.top().second;
                free_server.push({server[idx],idx});
                busy_server.pop();
            }
            // If no servers are free, fast-forward time to when the next server finishes
            if (free_server.empty()) {
                second = busy_server.top().first;
                while (!busy_server.empty() && busy_server.top().first <= second) {
                    int idx = busy_server.top().second;
                    free_server.push({server[idx], idx});
                    busy_server.pop();
                }
            }
            auto s = free_server.top();
            free_server.pop();
            ans.push_back(s.second);
            busy_server.push({second+task[j] , s.second});
            j++;
        }
        return ans;
    }
};