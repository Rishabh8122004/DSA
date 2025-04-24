class Solution {
public:
    bool isvalid(string s,int i,int j,vector<vector<int>>v,vector<string>& w,int l,int tw){
        int k = i;
        while(k<=j-l){
            string t = s.substr(k,l);
            int lo = 0,hi = v.size()-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(w[v[mid][0]] == t){if(v[mid][1] == 0)return false;v[mid][1]--;tw--;break;}
                else if(w[v[mid][0]] < t)lo = mid+1;
                else hi = mid-1;
            }
            k+=l;
        }
        return tw == 0;
    }
    vector<int> findSubstring(string s, vector<string>& w) {
        vector<vector<int>>v; // index of word, frequency of it
        vector<int>ans;
        sort(w.begin(),w.end());
        for(int i = 0;i<w.size();i++){
            int lo = 0,hi = v.size()-1;
            bool flag = false;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(w[v[mid][0]] == w[i]){flag = true;v[mid][1]++;break;}
                else if(w[v[mid][0]] < w[i])lo = mid+1;
                else hi = mid-1;
            }
            if(!flag)v.push_back({i,1});
        }
        int tw = w.size(),tl = tw*w[0].size(); // total words, total length after combination of all words
        int i = 0,j = 0,l = w[0].size();
        for(int i = 0; i + tl <= s.size(); i++){
            if(isvalid(s, i, i + tl, v, w, l, tw)) ans.push_back(i);
        }
        return ans;
    }
};