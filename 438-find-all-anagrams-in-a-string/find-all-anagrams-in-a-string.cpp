class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freqP(26, 0); // Frequency of characters in p
        vector<int> freqW(26, 0); // Frequency of characters in current window
        vector<int> ans;
        int k = p.size();
        int n = s.size();
        if(k > n) return ans;
        // Initialize frequencies for p and the first window of s
        for(char c : p){
            freqP[c - 'a']++;
        }
        for(int i = 0; i < k; i++){
            freqW[s[i] - 'a']++;
        }
        // Count initial matches between the two frequency arrays
        // We check if the count of 'a', 'b', ... 'z' is identical
        int matches = 0;
        for(int i = 0; i < 26; i++){
            if(freqP[i] == freqW[i]) matches++;
        }
        // Check the very first window (index 0)
        if(matches == 26){
            ans.push_back(0);
        }
        // Slide the window across s
        for(int i = k; i < n; i++){
            int right = s[i] - 'a';      // New character entering window
            int left = s[i - k] - 'a';   // Old character leaving window
            
            // --- Add Right Character ---
            // If it was matching before, it won't match after we add one more
            if(freqP[right] == freqW[right]) matches--;
            freqW[right]++;
            if(freqP[right] == freqW[right]) matches++;
            
            // --- Remove Left Character ---
            // If it was matching before, it won't match after we remove one
            if(freqP[left] == freqW[left]) matches--;
            freqW[left]--;
            if(freqP[left] == freqW[left]) matches++;
            if(matches == 26){
                ans.push_back(i - k + 1);
            }
        }
        
        return ans;
    }
};