class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five_cnt = 0;
        int ten_cnt = 0;
        int twenty_cnt = 0;

        for(int i =0;i<n;i++)
        {
            if(bills[i] == 5)
                five_cnt++;
            else if( bills[i] == 10)
            {
                ten_cnt++;
                if(five_cnt >0)
                    five_cnt--;
                else
                    return false;
            }
            else if(bills[i] == 20)
            {
                //we will try to save 5 
                if(ten_cnt > 0)
                {
                    ten_cnt--;
                    if(five_cnt >0)
                    five_cnt--;
                    else
                        return false;
                }
                else if(five_cnt >= 3)
                {
                    five_cnt -= 3;

                }
                else return false;
            }

        }

        return true;
        
    }
};