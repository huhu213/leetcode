class Solution {
public:
    bool jump(std::vector<int>& nums, int start, std::unordered_map<int, int>& mp) {
        if(nums[start] == 0) return false;
        if(start == nums.size()-1) return true;
        int gap = nums.size()-1-start;
        if(nums[start] >= gap) return true;
        if(mp.find(start) != mp.end()) {
            if(mp[start] == 0) return false;
            else if(mp[start] == 1) return true;
        }
        else {
            for(int i = nums[start]; i > 0; i --) {
                if(jump(nums, start+i, mp)) {
                    mp[start+i] = 1;
                    return true;
                }
            }
            mp[start] = 0;
            return false;
        }
    }
    
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        std::unordered_map<int, int> mp;
        if(nums[nums.size()-1] == 0) {
            nums.pop_back();
            int i = nums.size()-2;
            while(i >= 0 && nums[i] < nums.size()-1-i) {
                i --;
                nums.pop_back();
            }
            cout << i;
            if(i < 0) return false;
            else return jump(nums, 0, mp);
        }
        else return jump(nums, 0, mp);
    }
};
