class Solution {
public:
    int binarySearch(vector<int>& v, int target, int startIndex){
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

    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int minDistance = 0;
        if (len == 3)
        {
            return nums[0] + nums[1] + nums[2];
        }
        else
        {
            sort(nums.begin(), nums.end());
            int curIndex = 0;
            int nextIndex = 0;
            int currentSum = 0;
            int pivot = 0;
            int nextPivot = 0;
            int find = -1;
            int result = 0;

            minDistance = abs(nums[0] + nums[1] + nums[2] - target);
            while(curIndex < len-2){
                cout << "curIndex " << curIndex << endl;
                pivot = nums[curIndex];
                nextIndex = curIndex + 1;
                while(nextIndex < len-1){
                cout << "nextIndex " << nextIndex << endl;
                    nextPivot = nums[nextIndex];
                    currentSum = nums[curIndex] + nums[nextIndex];
                    int sumTarget = target - currentSum;
                    find = binarySearch(nums, sumTarget, nextIndex+1);
                    int i = 1;
                    if (find == -1)
                    {
                        while(find < 0 && i <= minDistance){
                           find = binarySearch(nums, sumTarget+i, nextIndex+1);
                           if (find > 0)
                           {
                               cout << "findOne " << nums[find] << endl;
                               minDistance = i;
                               result = currentSum + nums[find];
                               break;
                           }
                           else
                           {
                                find = binarySearch(nums, sumTarget-i, nextIndex+1);
                                if (find > 0)
                                {
                                    cout << "findTwo " << nums[find] << endl;
                                    minDistance = i;
                                    result = currentSum + nums[find];
                                    break;
                                }
                                i ++;
                           }
                        }
                    }
                    else
                    {
                        cout << "findThree " << nums[find] << endl;
                        minDistance = 0;
                        result = currentSum + nums[find];
                        return result;
                    }
                    nextIndex ++;
                    while(nums[nextIndex] == nextPivot){nextIndex ++;}
                }
                curIndex ++;
                while(nums[curIndex] == pivot){curIndex ++;}
            }
            return result;
        }
    }
};