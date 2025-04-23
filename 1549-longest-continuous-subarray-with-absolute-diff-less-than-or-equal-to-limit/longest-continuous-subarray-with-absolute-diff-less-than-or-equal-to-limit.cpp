class Solution {
public:
    class MinMax_Deque { // user-defined data structure, queue
public:
    deque<int>dqmin,dqmax; // dqmin for min element, dqmax for max element
    MinMax_Deque() { // constructor
        
    }
    
    void push(int x) {
       while(!dqmin.empty() && dqmin.back()>x){dqmin.pop_back();}
       dqmin.push_back(x);
       while(!dqmax.empty() && dqmax.back()<x){dqmax.pop_back();}
       dqmax.push_back(x);
    }
    
    void pop(int x) {
       if(!dqmin.empty() && dqmin.front() == x)dqmin.pop_front();
       if(!dqmax.empty() && dqmax.front() == x)dqmax.pop_front();
    }
    int getMax() {
        return dqmax.front();
    }
    int getMin() {
        return dqmin.front();
    }
};
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        if(n == 1)return 1;
        int i = 0,j = 0;
        MinMax_Deque dq;
        int ans = 0;
        while(j<n){
            dq.push(nums[j]);
            while((dq.getMax()-(dq.getMin()))>limit){dq.pop(nums[i]);i++;}
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};