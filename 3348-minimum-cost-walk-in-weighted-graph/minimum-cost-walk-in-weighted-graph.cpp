class Solution {
public:
    int fa[100005];
    int findFa(int x) {
        if (fa[x] == x) return x;
        return fa[x] = findFa(fa[x]);
    }
    void uni(int x, int y) {
        x = fa[x];
        y = fa[y];
        fa[x] = y;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for (int i = 0; i < n; i++) fa[i] = i;
        for (auto &x: edges) {
            findFa(x[0]);
            findFa(x[1]);
            uni(fa[x[0]], fa[x[1]]);
        }
        for (int i = 0; i < n; i++) findFa(i);
        unordered_map<int, int> Map;
        for (auto &x: edges) {
            if (!Map.count(fa[x[0]])) Map[fa[x[0]]] = x[2];
            else Map[fa[x[0]]] &= x[2];
        }
        vector<int> res;
        for (auto &x: query) {
            if (fa[x[0]] != fa[x[1]]) res.push_back(-1);
            else res.push_back(Map[fa[x[0]]]);
        }
        return res;
    }
};