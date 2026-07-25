class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;

        int n = s.size();
        string ans = ""; //empty string

        for(int i =0;i<n;i++)
        {
            //opening bracket
            if(s[i] == '(')
            {
                if(st.size() > 0) //there should be one bracket in stack which is not a part of new string
                ans += s[i];

                st.push(s[i]);
            }
            else //closing bracket
            {
                if(st.size() > 1 ) //then this closing bracket will be the part of my new string
                ans += s[i];

                st.pop();

            }

            //t.c = 0(n)
            //s.c = 0(n)

        }

        return ans;
        
    }
};