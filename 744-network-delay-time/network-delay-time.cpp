class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        
        for(auto &edge: times){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        while(!pq.empty()){
            auto [currDist, node] = pq.top();
            pq.pop();

            if(currDist > dist[node]) continue;

            for(auto &[adjNode, weight]: adj[node]){
                if(currDist + weight < dist[adjNode]){
                    dist[adjNode] = currDist + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxDist = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;
    }
};