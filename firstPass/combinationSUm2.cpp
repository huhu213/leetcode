class Solution {
public:
    int search(std::vector<int> nums, int s, int e, int target) {
        int l = s;
        int r = e;
        if(l <= r) {
            while(l <= r) {
                int m = (l+r)/2;
                if(nums[m] < target) l = m + 1;
                else if(nums[m] > target) r = m - 1;
                else return m;
            }
        }
        return -1;
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        if(candidates.size() == 0) return result;
        sort(candidates.begin(), candidates.end());
        int l = 0;
        int r = candidates.size()-1;
        int newTarget = target;
        while(candidates[r] > target) r --;
        if(candidates[r] == target) {
            std::vector<int> v;
            v.push_back(candidates[r]);
            result.push_back(v);
            while(candidates[r] == target) r --;
        }
        int rightBorder = r;
        while(l < r && candidates[l] <= target / 2) {
            int i = l;
            int j = r;
            vector<int> tmp;
            newTarget = target;
            while(i < j) {
                tmp.push_back(candidates[i]);
                newTarget -= candidates[i];
                if(newTarget < 0) break;
                else if(newTarget == 0) result.push_back(tmp);
                else {
                    int loc = search(candidates, i+1, j, newTarget);
                    if(loc != -1) {
                        tmp.push_back(candidates[loc]);
                        result.push_back(tmp);
                        tmp.pop_back();
                        i ++;
                        j = loc-1;
                    }
                    else {
                        i ++;
                    }
                }
            }
            l ++;
            if(candidates[l] == candidates[l-1]){
                r --;
                while(r > l && candidates[r] == candidates[r+1]) r --;
            } 
            else r = rightBorder;
        }
        return result;
    }
};