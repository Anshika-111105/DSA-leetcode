class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        // Step 1: Count frequency
        for (auto &w : words) {
            freq[w]++;
        }

        // Step 2: Custom comparator
        auto cmp = [](pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second < b.second; // lexicographically larger stays
            }
            return a.first > b.first; // min heap based on frequency
        };

        // Step 3: Min heap
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            decltype(cmp)
        > pq(cmp);

        // Step 4: Maintain top k
        for (auto &it : freq) {
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Step 5: Extract result
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Step 6: Reverse for correct order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};