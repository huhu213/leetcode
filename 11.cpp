class Solution {
public:
    int maxArea(vector<int>& height) {
    	int len = height.size();
    	if(len < 2)
    	{
    		return 0;
    	}
    	else
    	{
    		int leftLoc = 0;
            int rightLoc = len-1;
            int result = 0;

            while(leftLoc < rightLoc)
            {
                //固定一边，找到当前边的最大容积
                //基于最大面积只可能在height值超过当前height时出现这个前提
                if (height[leftLoc] < height[rightLoc])
                {
                    result = max(result, height[leftLoc] * (r-l));
                    int currentHeight = height[l];
                    leftLoc ++;
                    while(leftLoc < rightLoc && height[leftLoc] < currentHeight)
                    {
                        leftLoc ++;
                    }
                }
                else
                {
                    result = max(result, height[rightLoc] * (r-l));
                    int currentHeight = height[rightLoc];
                    rightLoc --;
                    while(leftLoc < rightLoc && height[rightLoc] < currentHeight)
                    {
                        rightLoc --;
                    }
                }
            }

            return result;
    	}
    }
};
