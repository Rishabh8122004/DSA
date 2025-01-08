class Solution {
public:
    vector<int> minOperations(string boxes) {
         int n = boxes.size();
        if(n == 1) return {0};
        vector<int> ans(n,0);
        vector<vector<int>> prefix(n,vector<int>(2,0));
        if(boxes[0] == '1'){prefix[0][0] += n-1;prefix[0][1] += 1;}
        for(int i = 1;i<n;i++){
            if(boxes[i] == '1'){
                prefix[i][0] += (n-1-i+prefix[i-1][0]);
                prefix[i][1] += (1+prefix[i-1][1]);
            }
            else{
                prefix[i][0] += prefix[i-1][0];
                prefix[i][1] += prefix[i-1][1];
            }
            cout<<prefix[i-1][0]<<" "<<prefix[i-1][1]<<"   ";
        }cout<<prefix[n-1][0]<<" "<<prefix[n-1][1]<<"   ";
        vector<vector<int>> sufix(n,vector<int>(2,0));
        if(boxes[n-1] == '1'){sufix[n-1][0] += n-1;sufix[n-1][1] += 1;}
        for(int i = n-2;i>=0;i--){
            if(boxes[i] == '1'){
                sufix[i][0] += (i+sufix[i+1][0]);
                sufix[i][1] += (1+sufix[i+1][1]);
            }
            else{
                sufix[i][0] += sufix[i+1][0];
                sufix[i][1] += sufix[i+1][1];
            }
        }
        cout<<endl;
        for(int i = 0;i<n;i++){
            cout<<sufix[i][0]<<" "<<sufix[i][1]<<"   ";
        }
        ans[0] = sufix[1][0];
        ans[n-1] = prefix[n-2][0];
        for(int i = 1;i<n-1;i++){
            ans[i]+=(sufix[i+1][0]-(i*sufix[i+1][1]));
            ans[i]+=(prefix[i-1][0]-((n-1-i)*prefix[i-1][1]));
        }
        return ans;
    }
};
