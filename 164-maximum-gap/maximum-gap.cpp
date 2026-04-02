class Solution {
public:
    void radix_sort(vector<int>&nums){
        int max_no = nums[0],n = nums.size();
        for(int i = 1;i<n;i++){
            max_no = max(max_no,nums[i]);
        }
        int nod = 0;//number of digit in maximum number
        while(max_no){
            nod++;
            max_no/=10;
        }
        vector<vector<int>>v(10),temp(10);

        int k = 0;
        while(k<nod){
            for(int i = 0;i<n;i++){
                int x = nums[i];
                x/=(pow(10,k));
                x%=10;
                v[x].push_back(nums[i]);
            }
            k++;
            int l = 0;
            for(int i = 0;i<v.size();i++){
                for(int j = 0;j<v[i].size();j++){
                    nums[l++] = v[i][j];
                }
            }
            v = temp;
        }
        return;
    }
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2)return 0;
        radix_sort(nums);
        int ans = 0;
        for(int i = 1;i<n;i++){
            ans = max(ans,abs(nums[i]-nums[i-1]));
        }
        return ans;
    }
};