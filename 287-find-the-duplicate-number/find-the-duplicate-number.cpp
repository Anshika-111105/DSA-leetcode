class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int slow = 0, fast = 0;
       
       // Phase 1: Detect cycle (meeting point)
       while(true){
           slow = nums[slow];
           fast = nums[nums[fast]];
           if(slow == fast){
               break;
           }
       }
       
       // Phase 2: Find cycle entrance (duplicate number)
       slow = 0;
       while(slow != fast){
           slow = nums[slow];
           fast = nums[fast];
       }
       
       return slow;
    }
};