class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) 
    {
        vector<int> ans;
        bool goingright = true;
        int r =0,c=0;
        while(r<grid.size())
            {
                if(goingright)
                {
                    for(int i = 0 ; i < grid[0].size();i++)
                        {
                            ans.push_back(grid[r][i]);
                        }
                    c = grid[0].size()-1;
                    r++;
                    goingright=false;
                }
                else
                {
                    for(int i = c ; i >=0 ; i--)
                        {
                            ans.push_back(grid[r][i]);
                        }
                    r++;
                    goingright=true;
                }
            }
        vector<int> finalans;
        for(int i =0 ; i< ans.size();i+=2)
                finalans.push_back(ans[i]);
        return finalans;
    }
};