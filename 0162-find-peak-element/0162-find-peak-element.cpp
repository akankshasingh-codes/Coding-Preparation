class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //brute force

        int n = nums.size();
        int idx = 0;

        if(nums[n-1] > nums[0]) 
            idx = n-1;
        
        
        for(int i =1;i<n-1;i++)
        {
            if(nums[i] > nums[i+1] && nums[i] > nums[i-1])
            {
                if(nums[i] > nums[idx])
                idx = i;
            }
        }

       
        return idx;
        //t.c = 0(n)
        //s.c = 0(1)
        
    }
};