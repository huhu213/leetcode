class Solution {
public:
   int myBinarySearch(vector<int>& v, int target, int startIndex){
        int l = startIndex;
        int r = v.size() - 1;
        while(l <= r){
            int middle = (r + l) >> 1;
            if (v[middle] < target)
            {
                l = middle + 1;
            }
            else if (v[middle] > target)
            {
                r = middle - 1;
            }
            else{
                return middle;
            }
        }
        return -1;
    }

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
            int curIndex = 0;
            int nextIndex = 1;
            int currentSum = 0;
            int pivot = 0;
            int nextPivot = 0;
            int i = 0;
            while(i < len-2)
            {
                curIndex = i;
                nextIndex = curIndex + 1;
                pivot = nums[curIndex];
                while(nextIndex < len-1){
                    currentSum = nums[curIndex] + nums[nextIndex];
                    nextPivot = nums[nextIndex];
                    int lastIndex = myBinarySearch(nums, -currentSum, nextIndex+1);
                    if (lastIndex > 0)
                    {
                        v.push_back(nums[curIndex]);
                        v.push_back(nums[nextIndex]);
                        v.push_back(nums[lastIndex]);
                        result.push_back(v);
                        v.clear();
                    }
                    nextIndex ++;
                    while(nums[nextIndex] == nextPivot)
                    {
                        nextIndex ++;
                    }
                }
                i ++;
                while(nums[i] == pivot)
                {
                    i++;
                }
            }
            return result;
        }
    }
};