class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2) return nums;
        int length = nums.size();
        std::unordered_set<int> numSet;
        for(int i = 0; i < length; i ++) {
            if(numSet.find(nums[i]) == numSet.end()) numSet.insert(nums[i]);
            else numSet.erase(nums[i]);
            cout << numSet.size() << endl;
        }
        std::vector<int> result;
        auto it = numSet.begin();
        result.push_back(*it);
        it ++;
        result.push_back(*it);
        return result;
    }
};