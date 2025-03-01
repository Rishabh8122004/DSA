class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        if(n<4)return 0;
        int ans = 0;
        sort(nums.begin(),nums.end());
        vector<int>v;
        for(int i = 0;i<n-1;i++){
            if(nums[i] != nums[i+1])v.push_back(nums[i]);
        }
        if(v.end() != nums.end())v.push_back(nums[n-1]);
        n = v.size();
        for(int i = 0;i<n-3;i++){
            for(int j = n-1;j>=i+3;j--){
                int k = i+1,l = j-1;
                int p1,p2;
                while(k<l){
                   p1 = v[i]*v[j];
                   p2 = v[k]*v[l];
                   if(p1 == p2){ans+=8;k++;}
                   else if(p1>p2)k++;
                   else if(p1<p2)l--;
                }
            }
        }
        return ans;
    }
};