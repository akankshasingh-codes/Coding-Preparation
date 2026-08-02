class Solution {
public:
void solve(int open ,int close, int total, string curr, vector<string> & ans)
{
    if(curr.size() == total)
    {
        ans.push_back(curr);
        return;
    }
    
    if(open < total)
        solve(open+1, close,total ,curr + '(', ans);
    if(close < open)
        solve(open, close+1,total ,curr + ')', ans);
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n,n, 2*n, "",ans);
        return ans;
        
    }
};