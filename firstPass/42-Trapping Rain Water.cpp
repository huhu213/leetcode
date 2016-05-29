class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        int i = 1;
        int length = height.size();
        int result = 0;
        while(i < length && height[i] >= height[i-1]) i++;
        int s = i-1;
        while(i < length) {
            int blocks = 0;
            while(i < length && height[i] < height[s]) {
                blocks += height[i];
                i ++;
            }
            if(i == length) {
                height[s] --;
                i = s + 1;
            }
            else {
                result = result + height[s] * (i-s-1) - blocks;
                while(i < length && height[i] >= height[i-1]) i ++;
                s = i-1;
            }
        }
        return result;
    }
};