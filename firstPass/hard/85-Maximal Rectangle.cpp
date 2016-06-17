class Solution {
public:
    vector<vector<int>> transMatrix(vector<vector<char>>& v) {
        if(v.size() == 0) {
            std::vector<vector<int>> v;
            return v;
        }
        //rows
        int m = v.size();
        //columns
        int n = v[0].size();
        std::vector<std::vector<int>> result(m, vector<int> (n));
        for(int i = 0; i < n; i ++) {
            if(v[m-1][i] == '0') result[m-1][i] = 0;
            else result[m-1][i] = 1;
        }

        for(int i = m-2; i >= 0; i --) {
            for(int j = 0; j < n; j ++) {
                if(v[i][j] == '0') result[i][j] = 0;
                else result[i][j] = result[i+1][j] + 1;
            }
        }

        return result;
    }

    int maxArea(std::vector<int> v) {
        if(v.size() == 0) return 0;
        if(v.size() == 1) return v[0];
        int area = 0;
        int len = v.size();
        for(int i = 0; i < len; i ++) {
           if(v[i] == 0) continue;
           else if(i >0 && v[i] == v[i-1]) continue;
           else {
                int l = i - 1;
                int r = i + 1;
                while(l > -1 && v[l] >= v[i]) l --;
                while(r < len && v[r] >= v[i]) r ++;
                area = max(area, (r-l-1) * v[i]);
           }
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        vector<vector<int>> transmatrix = transMatrix(matrix);
        int m = transmatrix.size();
        int n = transmatrix[0].size();
        int result = 0;
        for(int i = 0; i < m; i ++) {
            int area = maxArea(transmatrix[i]);
            if(area > result) result = area;
        }
        return result;       
    }
};