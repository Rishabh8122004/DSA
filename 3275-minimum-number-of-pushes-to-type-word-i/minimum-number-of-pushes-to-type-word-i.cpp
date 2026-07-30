class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int count = 0;
        int j = 0;
        for(int i = 0;i<word.size();i++){
            if(count%8 == 0)j++;
            ans += j;
            count++;
        }
        return ans;
    }
};