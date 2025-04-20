class Solution {
public:
    int numRabbits(vector<int>& a) {
        int n = a.size();
        vector<int>freq(1001);
        int ans = 0;
        for(int i = 0;i<n;i++){
           if(a[i] == 0)ans++;
           else{
            if(freq[a[i]] == 0){
                ans+=(a[i]+1);
                freq[a[i]] = a[i];
            }
            else if(freq[a[i]] > 0){
                freq[a[i]]--;
            }
           }
        }
        return ans;
    }
};