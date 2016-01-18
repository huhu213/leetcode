class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return;
        else {
            int i = len - 2;
            while(i > -1){
                if(nums[i] >= nums[i+1]) i--;
                else {
                    int tmp = nums[i];
                    int j = len - 1;
                    while(j > i && nums[j] <= nums[i]) j --;
                    nums[i] = nums[j];
                    nums[j] = tmp;
                    int gap = len - i - 1;
                    j = 0;
                    while(j < gap/2) {
                        int tmp = nums[len - 1 - j];
                        nums[len - 1 - j] = nums[i + 1 + j];
                        nums[i + 1 + j] = tmp;
                        j ++;
                    }
                    break;
                }
            }
            if(i == -1) {
                i = 0;
                while(i < len/2) {
                    int tmp = nums[len - 1 - i];
                    nums[len - 1 - i] = nums[i];
                    nums[i] = tmp;
                    i ++;
                }
            }

        }
    }
};