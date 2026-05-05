class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0,r = 0,maxlen = 0,k=2;
        unordered_map<int,int> mp;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0)mp.erase(fruits[l]);
                    l++;
                }
            }
            if(mp.size()<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;

        }
        return maxlen;
    }
};