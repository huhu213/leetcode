class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int length = nums.size();
        nums.push_back(-1);
        int loc = 0;
        int count = 0;
        while(count < length+1 && loc < length+1) {
            if(nums[loc] == loc) loc ++;
            else if(nums[loc] == length) {
                nums[length] = nums[loc];
                loc ++;
            }
            else {
                int tmp = nums[nums[loc]];
                nums[nums[loc]] = nums[loc];
                nums[loc] = tmp;
            }
            count ++;
        }
        int i = 0;
        while(i < length+1) {
            if(nums[i] == i) i++;
            else break;
        }
        return i;
    }
};
