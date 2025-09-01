class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };
        
        // Max-heap storing {gain, p, t}
        priority_queue<array<double,3>> pq;
        for (auto &c : classes) {
            int p = c[0], t = c[1];
            pq.push({gain(p, t), (double)p, (double)t});
        }
        
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            double p = top[1] + 1, t = top[2] + 1;
            pq.push({gain(p, t), p, t});
        }
        
        double total = 0.0;
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            total += top[1] / top[2];
        }
        
        return total / classes.size();
    }
};