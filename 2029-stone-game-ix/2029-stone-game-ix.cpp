class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        int cnt1 =0 , cnt2 = 0, cnt0 = 0;

        //counting the rem of each element after divding with 3
        for(int i =0;i<n;i++)
        {
            if( (stones[i] % 3) == 0)
                cnt0++;
            else if ( ( stones[i] % 3) == 1)
                cnt1++;
            else
                cnt2++;

        }

        //case 1: if cnt1 == cnt2 ==> alice win
        //case 2: if cnt1 > cnt2 or   ==> (i) if alice start with 2 then alice will win because bob will have sum%3 == 0
        //                           (ii) if alice start with 1 then in last chance bob will not have anything to choose sobob will loss
        // case 3: if cnt1 >= 1 or cnt2 >= 1 then alice will get more chance so alice will win


        //checking the above conditions

        if(cnt0 % 2 == 0) //even zeros then zeros will not effect the turn i.e can assume the turn of same person
        {
            if(cnt1 > 0 && cnt2 > 0)
                return true; // alice won
        }

        else if( abs(cnt1 - cnt2 ) > 2 )
            return true; //alice won

        // in other conditions except above alice will loss the game
        return false;

        //t.c = 0(n)
        //s.c = 0(1)      

        
        
    }
};