class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        if(nums.size() == 3) return max(max(nums[0], nums[1]), nums[2]);
        vector<int> money1(nums);
        vector<int> money2(nums);
        int len = nums.size();
        int pre_money = 0;
        int max_money = max(money1[0], money1[1]);
        for(int i = 2; i < len-1; i ++) {
            if(pre_money < money1[i-2]) pre_money = money1[i-2];
            money1[i] = pre_money + nums[i];
            if(money1[i] > max_money) max_money = money1[i];
        }
        int max_money2 = max(nums[1], nums[2]);
        pre_money = 0;
        for(int i = 3; i < len; i ++) {
            if(pre_money < money2[i-2]) pre_money = money2[i-2];
            money2[i] = pre_money + nums[i];
            if(money2[i] > max_money2) max_money2 = money2[i];
        }
        return max(max_money, max_money2);
    }
};