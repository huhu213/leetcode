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
    bool containAlmostDuplicate(vector<int>& nums, int t, int startPos, int endPos) {
        for(int i = startPos; i <= endPos; i ++) {
            for(int j = i+1; j <= endPos; j ++) {
                if((nums[i] == 2147483647 && nums[j] < 0) || (nums[j] == 2147483647 && nums[i] < 0))  continue;
                else if((nums[i] == -2147483648 && nums[j] > 0) || (nums[j] == -2147483648 && nums[i] > 0)) continue;
                else {
                    if(abs(nums[i]-nums[j]) <= t) return true;
                }
            }
        }
        return false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() <= 1) return false;
        if(t == 0) containsNearbyDuplicate(nums, k);
        else {
            if(nums.size() <= k) return containAlmostDuplicate(nums, t, 0, k-1);
            int startPos = 0;
            int endPos = k;
            while(endPos < nums.size()) {
                if(containAlmostDuplicate(nums, t, startPos, endPos)) return true;
                else {
                    startPos ++;
                    endPos ++;
                }
            }
            return false;
        }
    }
};