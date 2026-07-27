class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //sorting 
       

        int n = nums.size();

        sort(nums.begin(), nums.end());
       return ( nums[n-2]-1)*(nums[n-1]-1);

       //t.c = 0(nlogn)
       //s.c = 0(1)
        
    }
};