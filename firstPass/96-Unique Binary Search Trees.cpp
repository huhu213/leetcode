class Solution {
public:
    int numTrees(int n) {
        if(n < 3) return n;
        int result = 0;
        for(int i = 2; i < n; i ++) {
            int left = numTrees(i-1);
            int right = numTrees(n-i);
            result += left * right;
        }
        result += 2 * numTrees(n-1);
        return result;
    }
};