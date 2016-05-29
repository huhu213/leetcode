class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() == 2) return 1;
        vector<int> steps(nums.size(), 0);
        for(int i = nums.size()-2; i >= 0; i --) {
        	//one step to the end
            if(nums[i] + i >= nums.size()-1) {
                steps[i] = 1;
            }
            //can't go further
            else if(nums[i] == 0) steps[i] = -1;
            else {
            	//find min in steps that i can reach
                for(int j = nums[i]; j >= 1; j --) {
                    if(steps[i+j] == -1) continue;
                    else if(steps[i+j] == 1) {
                        steps[i] = 2;
                        break;
                    }
                    else {
                        if(steps[i] == 0) steps[i] = steps[i+j]+1;
                        else steps[i] = min(steps[i],steps[i+j]+1);
                    }
                }
                if(steps[i] == 0) steps[i] = -1;
            }
        }
        return steps[0];
    }
};