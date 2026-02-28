class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size() , 0);
        vector<int> right_max(height.size() , 0);
        int min_height = 0;
        int store_water = 0;
        left_max[0] = height[0];
        for(int i = 1 ; i < height.size() ; i++){
            left_max[i] = max(left_max[i - 1] , height[i]);
        }
        
        right_max[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2 ; i >= 0 ; i--){
            right_max[i] = max(right_max[i + 1] , height[i]);
        }
        for(int i = 0 ; i <= height.size() - 1 ; i++){
            
            min_height = min(left_max[i] , right_max[i]) - height[i];
            store_water += min_height;
        }
        return store_water;
    }
};