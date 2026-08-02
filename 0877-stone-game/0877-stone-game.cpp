class Solution {
public:
    int t[502][502];
    int solve(int i , int j , vector<int>& piles) //only thinking about p1
    {
        if(i > j) return 0;

        if(t[i][j] != -1) return t[i][j];
        int take_i = piles[i] + min( solve(i+2,j,piles) , solve(i+1,j-1,piles));
        int take_j = piles[j] + min( solve(i+1,j-1,piles) , solve(i,j-2,piles));

        return t[i][j] = max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        
        memset(t, -1, sizeof(t));
        int p1 = solve(0, piles.size()-1, piles);
        int total = accumulate(piles.begin(), piles.end(),0);
        int p2 = total - p1;

        if(p1 > p2)
            return true;
        return false;

        
    }
};