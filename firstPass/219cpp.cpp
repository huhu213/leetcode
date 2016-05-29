class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        else {
            map<int, int> arrayMap;
            for(int i = 0; i < nums.size(); i ++) {
                if(arrayMap.find(nums[i]) == arrayMap.end()) arrayMap[nums[i]] = i;
                else{
                    if(i - arrayMap[nums[i]] <= k)
                        return true;
                    else arrayMap[nums[i]] = i;
                }
            }
            return false;
        }
    }
};