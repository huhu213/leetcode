class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> result;
        if(num == 0) {
            result.push_back(num);
            return result;
        }
        if(num == 1) {
            result.push_back(0);
            result.push_back(1);
            return result;
        }
        int n = 1;
        int i = 0;
        while(n < num) {
            n = n * 2;
            i ++;
        }
        if(n == num) n = num - 1;
        else n = n / 2 - 1;
        std::vector<int> tmp = countBits(n);
        int l = tmp.size();
        for(int i = 0; i < 2*l + 1; i ++) {
            if(i < l) result.push_back(tmp[i]);
            else {
                result.push_back(tmp[i-l]+1);
            }
            if(i == num) break;
            else continue;
        }
        return result;
    }
};