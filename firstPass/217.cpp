class Solution {
public:
    void basicQuickSort(vector<int>& nums, int startPos, int endPos) {
        if(startPos < endPos) {
            int i = startPos;
            int j = endPos;
            int pivot = nums[startPos];
            while(i < j) {
                while(j > i && nums[j] >= pivot) j --;//从后想前找到比pivot小的数，放到nums[i]中
                if(i < j) {
                    nums[i] = nums[j];
                    i ++;
                }
                while(i < j && nums[i] < pivot) i ++;//从前往后找到比pivot大的数，放到nums[j]中
                if(i < j) {
                    nums[j] = nums[i];
                    j --;
                }
            }
            nums[i] = pivot;
            basicQuickSort(nums, startPos, i-1);
            basicQuickSort(nums, i+1, endPos);
        }
    }

    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2) return false;
        else {
            int i = 1;
            int len = nums.size();
            while(i < len && nums[i] > nums[i-1]) i ++;
            if(i == len) return false;//若数组为绝对升序，则返回false
            else if(i == 1) {
                while(i < len && nums[i] < nums[i-1]) i ++;
                if(i == len) return false;//若数组为绝对降序，则返回false
            }
            basicQuickSort(nums, 0, len-1);
            i = 1;
            while(i < len && nums[i] > nums[i-1]) i ++;
            return i == len ? false : true;
        }
    }
};