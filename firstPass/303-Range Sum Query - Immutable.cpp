class NumArray {
public:
    NumArray(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i ++) arr.push_back(nums[i]);
    }
    
    vector<int> arr;

    int sumRange(int i, int j) {
        if(j < i) {
            int tmp = j;
            j = i;
            i  = tmp;
        }
        int sumValue = 0;
        for(int s = i; s <= j; s ++) {
            sumValue += arr[s];
        }
        return sumValue;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);