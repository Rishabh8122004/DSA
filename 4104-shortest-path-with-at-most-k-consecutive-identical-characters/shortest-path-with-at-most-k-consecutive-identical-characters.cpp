class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& e, string l, int k) {
        vector<unordered_map<int,int>>shortest_path(n);//this will track all the nodes and the count maximum consecutive characters till now to reach the respective node , if possible(i.e. if count <= k)
        unordered_map<int,vector<pair<int,int>>>graph;
        for(int i = 0;i<e.size();i++){
            graph[e[i][0]].push_back({e[i][2],e[i][1]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int start_count = 1;// consecutive character to reach '0' from '0'
        pq.push({0,0,start_count});//distance to reach '0' , node '0' , count of maximum consecutive character

        shortest_path[0][start_count] = 0;
        while(!pq.empty()){
            int dist = pq.top()[0];// how much we traveled so far
            int u = pq.top()[1]; // our current node
            int count = pq.top()[2] ; // the maximum consecutive characters till current node
            pq.pop();
            for(auto &p : graph[u]){
                int next_dist = p.first; // what distance it would take to reach the next node 'v'
                int v = p.second; // the next node 

                int next_count = (l[u] == l[v]? count+1 : 1); // character is same as the last node character then increase the count , else start a new sequece of character

                if(next_count > k)continue; // we can not use this path

                int new_dist = dist+next_dist;
                if((shortest_path[v].find(next_count) == shortest_path[v].end())  || (new_dist < shortest_path[v][next_count])){
                    shortest_path[v][next_count] = new_dist;
                    pq.push({new_dist,v,next_count});
                }
            }
        }
        int ans = 1e9;
        for(auto &[c,dist] : shortest_path[n-1]){
            ans = min(ans,dist);
        }
        return (ans == 1e9?-1:ans);
    }
};