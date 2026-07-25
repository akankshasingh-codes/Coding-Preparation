class Solution {
public:
    string removeOuterParentheses(string s){

    //without using extar space

        int n = s.size();
        string ans = ""; //empty string
        int level = 0;

        for(int i =0;i<n;i++)
        {
            //opening bracket
            if(s[i] == '(')
            {
                if(level > 0) //there should be one bracket in stack which is not a part of new string
                ans += s[i];

                level++;
            }
            else //closing bracket
            {
                if(level > 1 ) //then this closing bracket will be the part of my new string
                ans += s[i];

                level--;

            }

            //t.c = 0(n)
            //s.c = 0(1)

        }

        return ans;
        
    }
};