class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> result;
        if(matrix.size() == 0) return result;
        if(matrix[0].size() == 0) return result;
        int m = matrix.size();
        int n = matrix[0].size();
        int allNums = m*n;
        int count = 0;
        //向右转边界条件：当前行数 == topborder
        int topborder = 0;
        //向下转边界条件：当前列数 == rightborder
        int rightborder = n-1;
        //向左转边界条件：当前行数 == bottomborder
        int bottomborder = m-1;
        //向上转边界条件：当前列数 == leftborder
        int leftborder = 0;
        while(count < allNums) {
            int i = topborder;
            int j = leftborder;
            //向右走
            while(count < allNums && j <= rightborder) {
                result.push_back(matrix[i][j]);
                count ++;
                j ++;
            }
            if(count == allNums) return result;
            rightborder --;
            j --;
            i ++;
            // 向下走
            while(count < allNums && i <= bottomborder) {
                result.push_back(matrix[i][j]);
                count ++;
                i ++;
            }
            if(count == allNums) return result;
            bottomborder --;
            i --;
            j --;
            //向左走
            while(count < allNums && j >= leftborder) {
                result.push_back(matrix[i][j]);
                count ++;
                j --;
            }
            if(count == allNums) return result;
            leftborder ++;
            j ++;
            i --;
            // 向上走
            while(count < allNums && i > topborder) {
                result.push_back(matrix[i][j]);
                count ++;
                i --;
            }
            if(count == allNums) return result;
            topborder ++;
            i ++;
            j ++;
            // cout << i << " " << j << endl;
        }
        return result;
    }
};