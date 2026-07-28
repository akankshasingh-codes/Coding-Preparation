class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int ans = 5001; //more than given range

        while(l <= r)
        {
            int m = (l+r)/2;
            ans = min(nums[m],ans);

            if(nums[l] <= nums[m]) //left part is sorted and min value will be nums[l]
            {
                ans = min(nums[l], ans);
                l = m+1; // now , will check on left side
            }
            else
            {
              ans = min( ans , nums[r]);
                r = m-1; // now , will check on left side  
            }
        }
        return ans;
        //t.c = 0(logn)
        //s.c = 0(1)
    }
};