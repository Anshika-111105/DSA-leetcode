class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> result(n);
        vector<int> outdegree(n),safe(n),answer;
        queue<int> q;
        for(int i=0;i<n;i++){
            for(auto& v:graph[i]){
                result[v].push_back(i);
            }
            outdegree[i]=graph[i].size();
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        while(q.size()){
            int u=q.front();
            q.pop();
            safe[u]=1;
            for(auto& v:result[u]){
                if(--outdegree[v]==0){
                    q.push(v);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(safe[i])answer.push_back(i);
        }
        return answer; 
    }
};