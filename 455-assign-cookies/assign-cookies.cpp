class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res=0,i=0;
        for(int j=0;j<g.size();j++)
        {
            while(i<s.size() && s[i]<g[j])
            {
                i++;
            }
            if(i == s.size())
            {
                return res;
            }
            res++;
            i++;
        }
        return res;
    
}};