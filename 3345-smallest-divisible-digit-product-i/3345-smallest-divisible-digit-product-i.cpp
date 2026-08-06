class Solution {
public:
    int calculatePro(int n)
    {
        int num = 1;
        while(n> 0)
        {
            int d = n%10;
            num *= d;
            n = n/10;
        }

        return num;
    }
    int smallestNumber(int n, int t) {

        int pro = calculatePro(n);

        while(pro % t != 0)
        {
            n++;
            pro = calculatePro(n);
            if(pro % t == 0)
                return n;

        }

        return n;
        
    }
};