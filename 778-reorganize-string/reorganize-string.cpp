class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        priority_queue<pair<int,char>> pq;
        for (auto &e : freq) {
            if (e.second > (s.size() + 1) / 2)
                return "";
            pq.push({e.second, e.first});
        }

        string result = "";
        pair<int,char> prev = {0, '#'}; // previous used character

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            result += curr.second;
            curr.first--;

            // push previous back AFTER using current
            if (prev.first > 0)
                pq.push(prev);

            prev = curr;
        }

        return result;
    }
};
