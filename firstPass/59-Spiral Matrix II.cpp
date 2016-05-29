class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 1));
        if(n == 0 || n == 1) return result;
        int count = 0;
        int allnums = n * n;
        int leftborder = 0;
        int rightborder = n-1;
        int topborder = 0;
        int bottomborder = n-1;
        while(count <= allnums) {
            int i = topborder;
            int j = leftborder;
            //向右走
            while(count < allnums && j <= rightborder) {
                result[i][j] = count + 1;
                count ++;
                j ++;
            }
            if(count == allnums) return result;
            j --;
            i ++;
            rightborder --;
            //向下走
            while(count < allnums && i <= bottomborder) {
                result[i][j] = count + 1;
                count ++;
                i ++;
            }
            if(count == allnums) return result;
            i --;
            j --;
            bottomborder --;
            //向左走
            while(count < allnums && j >= leftborder) {
                result[i][j] = count + 1;
                count ++;
                j --;
            }
            if(count == allnums) return result;
            j ++;
            i --;
            leftborder ++;
            //向上走
            while(count < allnums && i > topborder) {
                result[i][j] = count + 1;
                count ++;
                i --;
            }
            if(count == allnums) return result;
            i ++;
            j --;
            topborder ++;
        }
        return result;
    }
};