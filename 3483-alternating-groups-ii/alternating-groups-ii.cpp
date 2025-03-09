class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int>v;
        for(int i = 1;i<n;i++){
        if(colors[i] == colors[i-1]){
            int j = i;
            while(j<n){v.push_back(colors[j]);j++;}
            j = 0;
            while(j<i){v.push_back(colors[j]);j++;}
            break;
        }
        }
        if(v.size() == n){
            colors = v;
        }
        int ans = 0;
        int idx = -1;
        for(int i = 1;i<k;i++){
            if(colors[i] == colors[i-1]){idx = i-1;}
        }
        if(idx==-1)ans++;
        int i = 1,j = k;
        while(i<n){
            if(colors[j%n] == colors[(j-1)%n])idx = (j-1)%n;
            if(idx<i)ans++;
            if(idx<i && idx != -1 &&j%n<i)ans--;
            j++;i++;
        }
        return ans;
    }
};