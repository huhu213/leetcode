class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int minDistanse = 0;

		if (len == 3)
        {
        	return nums[0] + nums[1] + nums[2];
        }
        else
        {
        	sort(nums.begin(), nums.end());
        	int curIndex = 0;
        	int nextIndex = 0;
        	int lastIndex = 0;
        	int currentSum = 0;
        	int pivot = 0;
        	int nextPivot = 0;
        	int lastPivot = 0;
        	int i = 0; 
        	int result = 0;
        	minDistanse = abs(nums[0] + nums[1] + nums[2] - target);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
        	while(i < len-2){
        		curIndex = i;
        		pivot = nums[curIndex];
        		nextIndex = curIndex + 1;
        		while(nextIndex < len-1){
        			nextPivot = nums[nextIndex];
                    lastIndex = nextIndex + 1;
	        		while(lastIndex < len){
	        			currentSum = abs(nums[curIndex] + nums[nextIndex] + nums[lastIndex] - target);
	        			lastPivot = nums[lastIndex];
	        			if (currentSum <= minDistanse)
	        			{
	        			    cout << minDistanse << " " << currentSum << endl;
	        				minDistanse = currentSum;
	        				result = nums[curIndex] + nums[nextIndex] + nums[lastIndex];
	        			}
	        			lastIndex ++;
	        			while(nums[lastIndex] == lastPivot){lastIndex ++;}
	        		}
	        		nextIndex ++;
	        		while(nums[nextIndex] == nextPivot){nextIndex ++;}
        		}
        		i ++;
        		while(nums[curIndex] == pivot){curIndex ++;}
        	}
        	return result;
        }
    }
};