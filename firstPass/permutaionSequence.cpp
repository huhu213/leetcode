class Solution {
public: 
    bool place(vector<int> &permutation, int n) {
        for(int i = 0; i < n; i ++) {
            if(permutation[i] == permutaion[n]) return false;
        }
        return true;
    }

    void generate(vector<int> &permutation, int t, int n, int k, int &sum) {
        if(t == n) {
            sum ++;
        }
        else {
            for(int i = 0; i < n; i ++) {
                permutaion[t] = i;
                if(place(permutaion, t)) generate(permutaiton, t+1, n, k, sum);
                if(sum == k) return;
            }
        }
    } 
    string permutaionSequence(int n, int k) {
        vector<int> permutaion(n, 0);
        int sum = 0;
        generate(permutaion, 0, n, k, sum);
        string result;
        for(int i = 0; i < nums.size(); i ++) {
            ostringstream oss;
            oss << nums[i];
            result += oss.str();
        }
        return result;
    }
};