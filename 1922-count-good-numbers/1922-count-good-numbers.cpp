class Solution {
public:
    const int mod = 1e9 + 7;
    long long  power(long long base , long long exp)
    {
        long long ans = 1;
        while(exp > 0)
        {
            if(exp & 1) //odd exp
                ans = (ans * base) % mod;
            
            base = (base*base) % mod;
            exp >>= 1 ; //right shift to 1;
        }

        return ans;

    }
    int countGoodNumbers(long long n) {

        //applied alpha arrangment logic
        // 1. at a even place ==> 0, 2, 4 , 6, 8 ( 5 options)
        // 2. at a odd place ==> 2, 3 , 5, 7 ( prime no => 4 options)
        long long even_idx = (n+1)/2;
        long long odd_idx =  n/2;
        return  ( power(5,even_idx) * power(4,odd_idx) ) % mod; 
    }

    //t.c = 0(logn)
    //s.c = 0(1)
};