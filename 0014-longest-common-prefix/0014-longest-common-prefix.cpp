class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();

        //sorting the s
        sort(s.begin(), s.end());

        //take the first an last string and compare the char or both
        string first = s[0];
        string last = s[n-1];

        int len = min(first.size(), last.size());

        string lcp = "";

        for(int i =0;i<len;i++)
        {
            if(first[i] != last[i]) //char are not same
                break;
            lcp += first[i];
        }
        return lcp;
        //t.c = 0(nlogn + m)
        //s.c = 0(m)  
        
    }
};