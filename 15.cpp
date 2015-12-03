class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        int len = nums.size();
        std::vector<vector<int> > result;
        std::vector<int> v;
        if (len < 3)
        {
            return result;
        }
        else if (len == 3)
        {
            if (nums[0] + nums[1] + nums[2] == 0)
            {
                sort(nums.begin(), nums.end());
                result.push_back(nums);
                return result;
            }
            else
            {
                return result;
            }
        }
        else{
            sort(nums.begin(), nums.end());
            int currentIndex = 0;
            int newTarget = 0;
            int first = 0;
            int last = len-1;
            int firstPivot = 0;
            int lastPivot = 0;
            int pivot = 0;
            while(currentIndex < len-2){
                newTarget = 0 - nums[currentIndex];
                first = currentIndex + 1;
                last = len-1;
                pivot = nums[currentIndex];
                while(first < last){
                    firstPivot = nums[first];
                    lastPivot = nums[last];
                    if (nums[first] + nums[last] == newTarget)
                    {
                        v.clear();
                        v.push_back(nums[currentIndex]);
                        v.push_back(nums[first]);
                        v.push_back(nums[last]);
                        result.push_back(v);
                        first ++;
                        last --;
                        while(first <= last && nums[first] == firstPivot){first ++;}
                        while(last >= first && nums[last] == lastPivot){last --;}
                    }
                    else if (nums[first] + nums[last] < newTarget)
                    {
                        first ++;
                        while(first <= last && nums[first] == firstPivot){first ++;}
                    }
                    else{
                        last --;
                        while(last >= first && nums[last] == lastPivot){last --;}
                    }
                }
                currentIndex ++;
                while(currentIndex < len-2 && nums[currentIndex] == pivot){currentIndex ++;}
            }
            return result;
        }
    }
};