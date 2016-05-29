class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<int, bool> mp;
        unordered_map<int, bool> mprow;
        for(int row = 0; row < m; row ++) {
            bool flag = false;
            for(int col = 0; col < n; col ++) {
                if(matrix[row][col] == 0) {
                    if(mp.find(col) == mp.end()) {
                        flag = true;
                        mp[col] = true;
                        for(int i = 0; i < m; i ++) {
                            if(matrix[i][col] == 0) mprow[i] = true;
                            else matrix[i][col] = 0;
                        }
                        
                    }
                    else continue;
                }
            }
            if(flag || mprow[row]) for(int i = 0; i < n; i ++) matrix[row][i] = 0;
        }
    }
};