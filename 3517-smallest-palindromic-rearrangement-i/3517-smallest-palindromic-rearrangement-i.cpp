

class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string left = "";
        char mid = '\0';

        for (int i = 0; i < 26; i++) {

            // Add half of the occurrences to the left side
            for (int j = 0; j < freq[i] / 2; j++) {
                left += char('a' + i);
            }

            // Odd frequency character goes in the middle
            if (freq[i] % 2 == 1) {
                mid = char('a' + i);
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid != '\0')
            return left + mid + right;

        return left + right;
    }
};