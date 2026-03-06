class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        for(char c : s){
            count[c - 'a']++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < 26; i++){
            if(count[i] > 0){
                pq.push({count[i], i});
            }
        }
        string ans = "";
        while(pq.size() > 1){
            auto first = pq.top(); pq.pop();
            auto second = pq.top(); pq.pop();
            int f1 = first.first;
            int c1 = first.second;
            int f2 = second.first;
            int c2 = second.second;
            ans += char(c1 + 'a');
            ans += char(c2 + 'a');
            if(--f1 > 0){
                pq.push({f1, c1});
            }
            if(--f2 > 0){
                pq.push({f2, c2});
            }
        }
        if(!pq.empty()){
            auto last = pq.top();pq.pop();
            int freq = last.first;
            int ch = last.second;
            if(freq > 1){
                return "";
            }
            ans += char(ch + 'a');
        }

        return ans;
    }
};