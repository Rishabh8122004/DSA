class Solution {
public:
    void reverse(vector<int>& nums,int i , int j)
    {
        while(i<j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
       
        int n = nums.size();
        int pivot =-1;
        for(int i = n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                pivot = i;
                break;
            }
        }
        if(pivot==-1)
        {
            reverse(nums,0,n-1);
            return;
        }
        reverse(nums,pivot+1,n-1);
        for(int i = (pivot+1);i<n;i++)
        {
            if(nums[pivot]<nums[i])
           {swap(nums[pivot],nums[i]);
           break;
           }
        }
    }
};