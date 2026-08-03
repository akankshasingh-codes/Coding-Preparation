class Solution {
public:
     
     vector<int>dp;

    int solve(vector<int>& stone, int i, int n) //using recursion + memozation
    {
        if( i >= n)
            return 0; //now one can choose any stone
        if(dp[i] != -1)
            return dp[i];

        
        int res = INT_MIN;

        // when player take only one element
        res = stone[i] - solve(stone, i+1, n);

        if(i+1 < n) // when player take only starting two elements
            res = max(res, stone[i] + stone[i+1] - solve(stone, i+2, n) );
        
        if(i+2 < n) // when player take only starting three elements
            res  = max(res,stone[i] + stone[i+1] + stone[i+2] - solve(stone, i+3, n));
        
        
        return dp[i] = res ;
        
    }
    string stoneGameIII(vector<int>& stone) {
        
        int n = stone.size();
        dp.resize(n+1, -1);
        int diff = solve(stone, 0,n);

        if(diff > 0)
            return "Alice";
        else if ( diff < 0)
            return "Bob";
        else
            return "Tie";
        
    }
};