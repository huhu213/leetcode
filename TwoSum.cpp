class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	std::vector<int> result(2);
    	std::map<int, int> temp;
    	sort(nums.begin(), nums.end());
        int l = nums.size();
        int head = 0;
        int tail = l-1;
        if (l == 2)
        {
        	result.push_back(1);
        	result.push_back(2);
        	return result;
        }
        else{
        	for (int i = 0; i < l; ++i)
        	{
        		temp[nums[i]] = i;
        	}

        	while(head <= tail){
        		if (nums[head] + nums[tail] == target)
        		{
        			result.push_back(temp[nums[head]]+1);
        			result.push_back(temp[nums[tail]]+1);
        			return result;
        		}
        		else if (nums[head] + nums[tail] > target)
        		{
        			tail --;
        		}
        		else{
        			head ++;
        		}
        	}
        }
    }
}