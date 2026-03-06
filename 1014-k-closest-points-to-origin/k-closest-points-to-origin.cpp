class Solution {
public:
    int calcDistance(int x, int y){
        return x*x + y*y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, vector<int>>> pq; // max heap

        for(auto &point : points){
            int x = point[0];
            int y = point[1];

            int dist = calcDistance(x, y);

            pq.push({dist, point});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> result;

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};