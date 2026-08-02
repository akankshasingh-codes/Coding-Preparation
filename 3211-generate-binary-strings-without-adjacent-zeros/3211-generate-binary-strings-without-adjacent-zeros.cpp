class Solution {
public:
    void solve(int i , int n , string temp , vector<string>&ans)
    {
        //base case 
        if( i >= n)
        {
            ans.push_back(temp);
            return;
        }

        //skiping adjacent zero
        if( temp.empty() || temp.back() != '0')
            solve(i+1, n, temp + '0',ans);

        //can take 1 
        solve(i+1, n, temp + '1',ans);
    }
    vector<string> validStrings(int n) {
    
        int i = 0;
        vector<string>ans; 

        solve(i, n ,"", ans);
        return ans;
        //t.c = 0(n)
        //s.c = 0(n) for resursion calls
        
    }
};