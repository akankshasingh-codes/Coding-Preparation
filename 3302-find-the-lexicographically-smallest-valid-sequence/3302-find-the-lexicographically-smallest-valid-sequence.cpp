class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int>rightHnadSideMatchLength(n,0);
        int rightMatched = 0;
        int i = n-1;
        int j = m-1;

        while( i >= 0 )
        {
            if(j>= 0 && word1[i] == word2[j])
            {
                rightMatched++;
                j--;

            }
            rightHnadSideMatchLength[i] = rightMatched;
            i--;
        }

        vector<int>seq;
        bool changePower = true; // can change only one char 

        i = 0;
        j = 0;

        while(i < n && j < m)
        {
            if(word1[i] == word2[j])
            {
                seq.push_back(i);
                j++;
            }
            // can change this char because in remaining word all char will match
            else if(changePower == true && i + 1 < n && rightHnadSideMatchLength[i+1] >= m-j-1 )
            {
                seq.push_back(i);
                j++;
                changePower = false;

            }

            i++;
        }

        if( j == m)
            return seq;
        return {};

        
    }
};