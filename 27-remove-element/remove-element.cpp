class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int nod = 0; 
        for(int i = 0;i<nums.size()-nod;i++)
        {
            while(nums[i] == val && i<nums.size()-nod)
            {
                nod++;
                for(int j = i;j<nums.size()-1;j++)
                {
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        for(int i = 0;i<nod;i++)
        {
            nums.pop_back();
        }
        k = nums.size();
        return k;
    }
};