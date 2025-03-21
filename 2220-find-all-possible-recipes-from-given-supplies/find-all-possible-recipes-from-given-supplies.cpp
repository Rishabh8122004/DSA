class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>st(supplies.begin(),supplies.end());
        vector<bool>v(recipes.size(),false);
        vector<string> ans;
        int x = recipes.size();
        while(x--){
            if(ans.size() == recipes.size())break;
        for(int i = 0;i<recipes.size();i++){
            bool flag = true;
            if(v[i])continue;
            for(int j = 0;j<ingredients[i].size();j++){
                if(!st.count(ingredients[i][j])){flag = false;break;}
            }
            if(flag){ans.push_back(recipes[i]);st.insert(recipes[i]);v[i] = true;}
        }
        }
        return ans;
    }
};