class Solution {
public:
    int solve_sum(int n)
    {
        int sum = 0;

        while(n != 0)
        {
            int d = n%10;
            sum += d;
            n = n/10;
        }

        return sum;
    }

    int solve_pro(int n)
    {
        int pro = 1;

        while(n != 0)
        {
            int d = n%10;
            pro *= d;
            n = n/10;
        }

        return pro;

    }
    bool checkDivisibility(int n) {
        int sum_of_digit = solve_sum(n);
        int pro_of_digit = solve_pro(n);

        int total = sum_of_digit + pro_of_digit;

        if(n % total == 0)
            return true;
        else
            return false;

        //t.c = 0(n)
        //s.c = 0(1)
        
    }
};