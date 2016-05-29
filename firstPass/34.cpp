#include <vector>

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int startPos, int endPos) {
        int left = startPos;
        int right = endPos;
        while(left <= right) {
            int middle = (left + right) / 2;
            if(nums[middle] == target) return middle;
            else if(nums[middle] > target) {
                right = middle - 1;
            }
            else left = middle + 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        std::vector<int> result;
        if(binarySearch(nums, target, 0, len-1) == -1) return result;
        else {
            int startPos = 0;
            int endPos = len-1;
            int pivot = binarySearch(nums, target, startPos, endPos);
            int middle = pivot;
            while(middle != -1) {
                endPos = middle - 1;
                middle = binarySearch(nums, target, startPos, endPos);
            }
            result.push(middle+1);
            middle = pivot;
            endPos = len-1;
            while(middle != -1) {
                startPos = middle + 1;
                middle = binarySearch(nums, target, startPos, endPos);
            }
            result.push(startPos);
            return result;
        }
    }
}; 
