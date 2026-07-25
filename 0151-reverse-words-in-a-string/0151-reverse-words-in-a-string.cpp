class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";

        string temp = "";

        for(int i =0;i<n;i++)
        {
            if(s[i] != ' ') //not null char
            {
                temp += s[i];
            }
            else //delimeter point
            {
                if(!temp.empty())
                {
                    //either temp could be first word 
                    if(ans.empty())
                        ans = temp;
                    else
                        ans = temp + " " + ans;
                    temp = ""; //set to the empty string
                }

            }
        }

        //handling the last word
        if(!temp.empty())
        {
            //either temp could be first word 
            if(ans.empty())
                ans = temp;
            else
                ans = temp + " " + ans;
                temp = ""; //set to the empty string
        }

        return ans;

        //t.c = 0(n)
        //s.c = 0(1)
        
    }
};