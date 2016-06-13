class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int l = nums.size();
        int i = 0;
        while(i < l-2) {
        	int j = i+1;
        	while(j < l-1) {
        		if(nums[j] <= nums[i]) j ++;
        		else {
        			int k = j + 1;
        			while(k < l) {
        				if(nums[k] <= nums[j]) k ++;
        				else return true;
        			}
        			j ++;
        		}
        	}
        	i ++;
        }
        return false;
    }
};