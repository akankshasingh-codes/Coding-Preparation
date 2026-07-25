class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //method 2 ==> binary Search

        int n = nums.size();
        
        int l = 0;
        int r = n-1;

        while(l < r)
        {
            int m = (r-l)/2 + l;
            if (nums[m] < nums[m+1])
                l = m+1;
            else 
                r = m;    
        }
        return l;
        //t.c = 0(logn)
        //s.c = 0(1)
        
    }
};