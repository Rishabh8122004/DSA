class Solution {
public:
    int find_nearest_prime(int x,vector<int>&p){
        if(x == 1)return 1;//nearest prime
        int lo = 0,hi = p.size()-1;
        int higher_prime = 2; // unnecessary lower prime
        while(lo<=hi){ // finding prime higher than x
            int mid = lo+(hi-lo)/2;
            if(p[mid]<x) lo = mid+1;
            else {
                hi = mid-1;
            }
        }
         higher_prime = p[lo];
        return higher_prime-x;
    }
    bool is_prime(int x){
        for(int i = 2;i<=sqrt(x);i++){
            if(x%i == 0)return false;
        }
        return x != 1;
    }
    int minOperations(vector<int>& nums) {
        vector<int>p;
        int n = nums.size(),m = nums[0];
        for(int i = 0;i<n;i+=2){
            m = max(m,nums[i]);
        }
        p.push_back(2);
        int i = 3;
        while(p.back()<m){
            if(is_prime(i))p.push_back(i);
            i++;
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(i%2 == 0){
                if(!is_prime(nums[i])){
                    ans += find_nearest_prime(nums[i],p);// will return the value to add to reach nearest prime
                }
            }
            else{
               if(is_prime(nums[i])) ans += (nums[i] == 2?2:1);
            }
        }
        return ans;
    }
};