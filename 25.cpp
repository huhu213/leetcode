class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;
        else {
            int cur = 0;
            int length = 1;
            while(cur < len) {
                int next = cur + 1;
                while(next < len && nums[next] == nums[cur]) next ++;
                if(next < len) {
                    nums[length ++] = nums[next];
                    cur = next;
                }
                else return length;
            }
            return length;
        }
    }
};