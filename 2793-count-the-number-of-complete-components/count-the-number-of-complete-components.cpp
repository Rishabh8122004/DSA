class Solution {
public:
class node{
    public:
    int val ;
    vector<node*>conn;
    node(int x){
        this->val = x;
    }
};
    void solve(node* n,vector<int>&vis,set<pair<int,int>>&edges,int &nodes){
        for(node* i: n->conn){
            edges.insert({n->val,i->val});
            if(vis[i->val] == 0){
                nodes++;
                vis[i->val] = 1;
                solve(i,vis,edges,nodes);
            }
        }
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& e) {
        unordered_map<int,node*>mp;
        for(int i = 0;i<n;i++){
            mp[i] = new node(i);
        }
        for(int i = 0;i<e.size();i++){
            mp[e[i][0]] -> conn.push_back(mp[e[i][1]]);
            mp[e[i][1]] -> conn.push_back(mp[e[i][0]]);
        }
        vector<int>vis(n,0);
        int nodes = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            set<pair<int,int>>edges;
            nodes = 1;
            if(vis[i] == 0){
                vis[i] = 1;
                solve(mp[i],vis,edges,nodes);
                if(edges.size()/2 == ((nodes*(nodes-1))/2))ans++;
            }
            
        }
        return ans;
    }
};