class Solution {
public:
     
    string stoneGameIII(vector<int>& stone) { //bottom up approach
        
        //can use three variable in place of dp
        int n = stone.size();
        int res = INT_MIN; //dp[i]
        int a = 0; // dp[i+1]
        int b = 0 ; //dp[i+2]
        int c = 0; //dp[i+3]

        for(int i = n-1; i >= 0 ;i--)
        {
            // when player take only one element
            res = stone[i] - a;

            if(i+2 <= n) // when player take only starting two elements
            res = max(res, stone[i] + stone[i+1] - b);

            if(i+3 <= n) // when player take only starting three elements
            res  = max(res,stone[i] + stone[i+1] + stone[i+2] - c);

            c = b;
            b = a ;
            a = res;
        }

        int diff = a;

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