class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) {
            if(nums[0] == 1) return 0;
            else return 1;
        }
        int i = 0;
        int loc = 0;
        while(i < nums.size()) {
            if(nums[i] == i) i ++;
            else {
                loc = nums[i];
                if(loc == nums.size()) nums.push_back(loc);
                else if(nums[loc] == loc) i ++;
                else {
                    nums[i] = nums[loc];
                    nums[loc] = loc;
                }            
            }
        }
        i = 0;
        while(i < nums.size() && nums[i] == i) i ++;
        return i;
    }
};
