class Solution {
public:
    
    long long can_eat(int b  ,vector<int>& piles )
    {
        int n = piles.size();
        long long int cnt = 0;

        for(int i =0;i<n;i++)
        {
            cnt += ( (double)piles[i] + b -1 )/b;
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //brute froce ==> start eatint from 1 banana to max of ith piles
        //binary seach ==> set a boundary from min to max , koko can eat banana

        int mini = 1;
        int maxi = *max_element(piles.begin(), piles.end());
        int ans = maxi;

        while(mini <= maxi)
        {
            int b = ( maxi - mini)/2 + mini;  // can each b banana in one hour
            long long int  hours = can_eat(b,piles); //if koko eating b banana , taking time to fifnish all banana = hours

            if(hours <= h)// decrease the cnt of bana to eat
            {
                ans = min(b,ans);
                maxi = b-1;
            }
            else
                mini = b+1;  
        }

        return ans;
        //t.c = 0(n*log n)
        //s.c = 0(1)
        
        
    }
};