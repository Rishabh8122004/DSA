class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans = INT_MIN;
        for(int i = 0;i<grid.size();i++){ // calculating max element
            for(int j = 0;j<grid[i].size();j++){
                ans = max(ans,grid[i][j]);
            }
        }
        vector<pair<int,bool>> v(ans+1,{0,false}); // making a vector which will store if the index is present in grid as an element , to reduce complexity and avoid sorting function
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                v[grid[i][j]].second = true;
                v[grid[i][j]].first++;

            }
        }
        ans = 0;
        vector<int> ele; // making a vector storing all the element present in grid but in sorted manner
        for(int i = 0;i<v.size();i++){if(v[i].second){while(v[i].first--){ele.push_back(i);}}}
        int i = ele.size()/2;// middle element
            bool flag = true; 
            for(int j = 0;j<grid.size();j++){ // iterating through grid and calculating the operation require to make the current element equal to middle element.
                for(int k = 0;k<grid[j].size();k++){
                int d = ele[i]-grid[j][k];
                if(d%x != 0){flag = false;break;}
                d = abs(d);
                ans+=(d/x);
                }
                if(!flag)return -1; // if there is no way 
            }
        return ans;
    }
};