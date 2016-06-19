class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> money(nums);
        int len = nums.size();
        int pre_max_money = 0;
        money[0] = nums[0];
        money[1] = nums[1];
        int max_money = max(nums[0], nums[1]);
        for(int i = 2; i < len; i ++) {
            if(pre_max_money < money[i-2]) pre_max_money = money[i-2];
            money[i] = nums[i] + pre_max_money;
            if(money[i] > max_money) max_money = money[i];
        }
        return max_money;
    }
};