class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        else {
            int len = nums.size();
            map<int, bool> isVisited;
            int i = 0;
            while(isVisited.size() < len) {
                while(i < len) {
                    if(nums[i] == target) return i;
                    else {
                        if(isVisited.find(nums[i]) == isVisited.end()) {
                            isVisited[nums[i]] = true;
                            i ++;
                        }
                        else i ++;
                    }
                    
                }
                if(i == len) i = 0;
            }
            return -1;
        }
    }
};