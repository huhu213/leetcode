using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
    	std::vector<vector<int> > v;
    	if (nums.size() == 0)
    	{
    		return v;
    	}
    	else
    	{
    		int len = nums.size();
    		sort(nums.begin(), nums.end());
    		int i = 0;
    		while(i < len-3)
    		{
    			if(i > 0)
    			{
    			    while(nums[i-1] == nums[i]){i ++;}
                }
    			int j = i + 1;
    			while(j < len - 2)
    			{
    				if(j > i+1)
                    {
                        while(nums[j-1] == nums[j]){j ++;}
                    }
    				std::vector<int> temp;
    				int newTarget = target -  nums[i] - nums[j];
    				int head = j + 1;
    				int tail = len - 1;
    				while(head < tail){
    					if (nums[head] + nums[tail] == newTarget)
    					{
    						temp.push_back(nums[i]);
    						temp.push_back(nums[j]);
    						temp.push_back(nums[head]);
    						temp.push_back(nums[tail]);
    						v.push_back(temp);
    						temp.clear();
    						head ++;
    						tail --;
    						if(nums[head] == nums[head-1]){while(nums[head] == nums[head-1]){ head ++;}}
    						if(nums[tail] == nums[tail+1]){while(nums[tail] == nums[tail+1]){ tail --;}}
    					}
    					else if (nums[head] + nums[tail] < newTarget)
    					{
    					    head ++;
    					    if(nums[head] == nums[head-1])
    					    {
    					        while(nums[head] == nums[head-1]){head ++;}
    					    }
    					}
    					else
    					{
    						tail --;
    					    if(nums[tail+1] == nums[tail])
    					    {
    					        while(nums[tail+1] == nums[tail]){tail --;}
    					    }
    					}
    				}
    				j ++;
    			}
    			i ++;
    		}
    		return v;
    	}
    }
};