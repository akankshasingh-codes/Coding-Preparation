class Solution {
public:
    int maximumLengthSubstring(string s) {
        int resLen = 0;
        vector<int>freq(26,0);

        for(int l = 0, r = 0 ;r < s.size();r++)
        {
            freq[s[r] -'a']++; // storing freq of each char

            while(freq[s[r]-'a'] > 2)
            {
                freq[s[l]-'a']--;
                l++;
            } 

            resLen = max(resLen, r-l+1);
        }

        return resLen;

        //t.c = 0(n)
        //s.c = 0(26) constant
        
    }
};