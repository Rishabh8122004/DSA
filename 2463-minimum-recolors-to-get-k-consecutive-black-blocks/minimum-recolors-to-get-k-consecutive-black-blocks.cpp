class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX,sum = 0;
        for(int i = 0;i<k;i++)if(blocks[i] == 'W')sum++;
        if(sum<ans)ans = sum;
        int i = 1,j = k;
        while(j<blocks.size()){
            if(blocks[j] == 'W')sum++;
            if(blocks[i-1] == 'W')sum--;
            i++;j++;
            ans = min(ans,sum);
        }
        return ans;
    }
};