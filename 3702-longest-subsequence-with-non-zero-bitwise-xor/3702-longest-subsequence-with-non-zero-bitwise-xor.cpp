class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        int n = nums.size();
        bool hasNonZero = false;

        for(int i =0;i<n;i++)
        {
            totalXor ^= nums[i];
            if(nums[i] != 0)
                hasNonZero = true;
        }

        if(totalXor != 0)
            return n;
        
        if(hasNonZero == true)
            return n - 1;
        
        return 0 ;

        //t.c = 0(n)
        //s.c = 0(1)
        
    }
};