class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        std::unordered_map<int, int> numMap;
        for(int i = 0; i < length; i ++) {
            if(numMap.find(nums[i]) == numMap.end()) numMap[nums[i]] = 1;
            else {
                if(numMap[nums[i]] == 2) numMap.erase(nums[i]);
                else numMap[nums[i]] = 2;
            }
        }
        auto it = numMap.begin();
        return it->first;
    }
};