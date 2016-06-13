class Solution {
public:
    int generate(vector<int>& nums, int s, int e) {
        if(e - s < 2) return -1;
        int m = (s + e) / 2;
        if(nums[m] > nums[m+1] && nums[m] > nums[m-1]) return m;
        else {
            int index = generate(nums, s, m);
            if(index != -1) return index;
            else {
                index = generate(nums, m, e);
                return index;
            } 
        }
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        int l = nums.size();
        if(nums[l-1] > nums[l-2]) return l-1;
        return generate(nums, 0, l);
    }
};