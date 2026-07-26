class Solution {
public:
    bool check(string s, string t)
    {
        unordered_map<char, char>mp;
        int n = s.size();

        for(int i =0;i<n;i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                if(mp[s[i]] != t[i]) 
                    return false;
            }
            else
            mp[s[i]] = t[i];
            
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {

        bool ans1 = check(s,t);
        bool ans2 = check(t,s);

        if(ans1 && ans2)
            return true;
        
        return false;
        //t.c = 0(n)
        //s.c = 0(26)
        
        
    }
};