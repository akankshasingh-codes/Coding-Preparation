class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < n;i++)
        {
            mp[nums[i]]++;
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);

        }

        vector<int>ans;

        for(int i = mini; i <= maxi; i++)
        {
            if(mp.find(i) == mp.end()) // missing no
            ans.push_back(i);
        }

        return ans;
        //t.c = 0(2n)
        //s.c = 0(n)
        
    }
};