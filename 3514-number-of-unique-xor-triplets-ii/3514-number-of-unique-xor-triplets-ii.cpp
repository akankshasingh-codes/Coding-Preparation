class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n = nums.size();

        const int max_ = 2048;
        vector<bool>xor_pair(max_ + 1, false);
        vector<bool>xor_final(max_ + 1, false);

        //store all possible pair
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                xor_pair[nums[i]^nums[j]] = true;
            }
        }

        int cnt = 0;

        //compute xor with third element
        for(int i =0;i<n;i++)
        {
            for(int j = 0; j < max_; j++)
            {
                if(xor_pair[j] == true)
                {
                    int x = nums[i]^j;

                    if(!xor_final[x])
                    {
                        cnt++;
                        xor_final[x] = true;
                    }
                }
            }
        }

        return cnt;
        //t.c = 0(n*n)
        //s.c = 0(1) ==> using constant space


        
    }
};