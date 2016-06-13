class Solution {
public:
    vector<vector<int>> generate(int k, int n, int s, int e) {
        if(s >= e) {
            vector<vector<int>> result;
            return result;
        }
        if(k == 1 && e > n) {
            vector<int> tmp(1, n);
            vector<vector<int>> result(1, tmp);
            return result;
        }
        if(k == 2 && s < e) {
            int l = s, r = min(9, e-1);
            vector<vector<int>> result;
            while(l < r) {
                if(l + r == n) {
                    vector<int> tmp(2);
                    tmp[0] = l;
                    tmp[1] = r;
                    result.push_back(tmp);
                    l ++;
                    r --;
                }
                else if(l + r > n) {
                    r --;
                }
                else l ++;
            }
            return result;
        }
        vector<vector<int>> result;
        int start = min(9, n-1);
        for(int i = start; i > n / k; i --) {
            vector<vector<int>> preResult = generate(k-1, n-i, s, i);
            for(int j = 0; j < preResult.size(); j ++) {
                if(preResult[j][k-2] >= i) continue;
                else {
                    preResult[j].push_back(i);
                    result.push_back(preResult[j]);
                }
            }
        }
        return result;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k == 1) {
            vector<int> tmp(1, 1);
            vector<vector<int>> result(1, tmp);
            return result;
        }
        else return generate(k, n, 1, n);
    }
};
