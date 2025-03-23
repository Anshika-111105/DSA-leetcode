class Solution {
public:
    typedef long ll;
    typedef pair<ll,int> P;
    const int MOD = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<P> adj[n];
        vector<ll> distance(n, LONG_MAX);
        vector<int> NumberOfWays(n, 0);
        priority_queue<P, vector<P>, greater<P>> pq;

        for(auto &e : roads){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        pq.push({0, 0});
        distance[0] = 0;
        NumberOfWays[0] = 1;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int root = top.second;
            ll cost = top.first;
            if(cost < distance[root]) continue;

            for(auto &nbr : adj[root]){
                ll total = cost+nbr.second; 
                if( total < distance[nbr.first]){
                    distance[nbr.first] = total;
                    NumberOfWays[nbr.first] = NumberOfWays[root];
                    pq.push({distance[nbr.first], nbr.first});
                }
                else if(total == distance[nbr.first]){
                    NumberOfWays[nbr.first] = (NumberOfWays[nbr.first] + NumberOfWays[root])%MOD;
                }
            }
        }

        return NumberOfWays[n-1];
    }
};