class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        std:unordered_set<int> s;
        int i = 0;
        int result = nums[0];
        while(s.size() < nums.size()) {
            if(i == nums.size()) i = 0;
            if(s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
                result = min(result, nums[i]);
            }
            i ++;
        }
        return result;
    }
};