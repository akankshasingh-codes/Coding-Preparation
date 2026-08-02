class Solution {
public:
    int helper(int i , int n , string s , int sign, long long num)
    {
        //base case
        if( i >= n || !isdigit(s[i]))
            return (int) num*sign ;
        
          int d = s[i] -'0';

        //update the num with current digit
        num = num*10 + d;
        
        if(sign * num <= INT_MIN)
            return INT_MIN;
        if(sign * num >= INT_MAX)
            return INT_MAX;
        
        return helper(i+1,n,s,sign,num);
        
    }

    int myAtoi(string s) {
        int n = s.size();
        int i =0;

        //1. ignoring leading space
        while( i < n && s[i] == ' ') i++;

        //2 . checking the sign
        int sign = 1;
        if(i < n && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        //3. calling the helper function
        return helper(i,n, s, sign, 0);
        //s.c = 0(N)
        //t.c = 0(N)

        
    }
};