class Solution {
public:
     
    string stoneGameIII(vector<int>& stone) { //bottom up approach
        
        int n = stone.size();
        vector<int>dp(n+1);

        for(int i = n-1; i >= 0 ;i--)
        {
            // when player take only one element
            dp[i] = stone[i] - dp [i+1];

            if(i+2 <= n) // when player take only starting two elements
            dp[i] = max(dp[i], stone[i] + stone[i+1] - dp[i+2]);

            if(i+3 <= n) // when player take only starting three elements
            dp[i]  = max(dp[i],stone[i] + stone[i+1] + stone[i+2] - dp[i+3]);
        }

        int diff = dp[0];

        if(diff > 0)
            return "Alice";
        else if ( diff < 0)
            return "Bob";
        else
            return "Tie";

            //t.c = 0(n)
            //s.c = 0(1) due to recursion

        
    }
};