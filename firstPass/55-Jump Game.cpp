class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        if(nums[0] == 0) return false;
        int mostfar = nums[0];
        // mp记录当前位置能到达的最远的位置
        for(int i = 1; i < nums.size(); i ++) {
            if(mostfar >= nums.size()-1) return true;
            else if(mostfar < i) return false;
            else if(mostfar == i && nums[i] == 0) return false; 
            if(i + nums[i] > mostfar) mostfar = i + nums[i];
        }
    }
};
