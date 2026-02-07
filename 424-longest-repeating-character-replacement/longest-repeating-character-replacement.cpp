class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxLen = 0, maxFreq = 0;
        unordered_map<char, int> freq;
        while (r < s.length()) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            while ((r - l + 1) - maxFreq > k) { // if replacements needed > k, shrink window
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
