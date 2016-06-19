class Solution {
public:
    vector<vector<int>> generate(vector<int> nums, vector<vector<int>>& result, int lastSize) {
        for(int i = 1; i < nums.size(); i ++) {
            int len = result.size();
            if(nums[i] == nums[i-1]) {
                for(int j = len-lastSize; j < len; j ++) {
                    vector<int> tmp = result[j];
                    tmp.push_back(nums[i]);
                    result.push_back(tmp);
                }
            }
            else {
                lastSize = len;
                for(int j = 0; j < len; j ++) {
                    vector<int> tmp = result[j];
                    tmp.push_back(nums[i]);
                    result.push_back(tmp);
                }
            }
        }
        return result;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> empty_set;
        result.push_back(empty_set);
        if(nums.size() == 0) return result;
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        tmp.push_back(nums[0]);
        result.push_back(tmp);
        if(nums.size() == 1) return result;
        return generate(nums, result, 1);
    }
};