class Solution {
public:

    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> bitwords(len);

        for(int i = 0; i < len; i++) {
            int sz = words[i].size();
            for(int j = 0; j < sz; j++) {
                bitwords[i] |= (1 << (words[i][j] - 'a'));
            }
        }

        int result = 0;
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < i; j++) {
                if(bitwords[i] & bitwords[j]) continue;
                int p = words[i].size()*words[j].size();
                if(p > result) result = p;
            }
        }

        return result;
    }
};