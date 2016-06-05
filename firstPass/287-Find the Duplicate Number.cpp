class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int r = n;
        while(l < r) {
            int m = (l + r)/2;
            int sum = 0;
            for(int i = 0; i < n; i ++) {
                if(nums[i] <= m) sum ++;
            }
            if(sum > m) r = m;
            else l = m + 1;
        }
        return l;
    }
};