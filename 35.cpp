class Solution {
public:
    int specificBinarysearch(std::vector<int>& nums, int target, int startPos, int endPos) {
        int left = startPos;
        int right = endPos;
        while(left <= right) {
            int middle = (left + right) / 2;
            if(nums[middle] == target) return middle;
            else if(nums[middle] > target) {
                right = middle - 1;
                if(right < 0) return 0;
                else if(nums[right] < target) return right+1;
            }
            else {
                left = middle + 1;
                if(left == nums.size()) return nums.size();
                else if(nums[left] > target) return left;
            }
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        return specificBinarysearch(nums, target, 0, len-1);
    }
};