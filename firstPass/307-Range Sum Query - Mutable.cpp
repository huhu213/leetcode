class NumArray {
public:
    NumArray(vector<int> &nums) {
       for(int i = 0; i < nums.size(); i ++) arr.push_back(nums[i]); 
    }
    vector<int> arr;
    void update(int i, int val) {
        arr[i] = val;
    }

    int sumRange(int i, int j) {
        int result = 0;
        for(int s = i; s <= j; s ++) result += arr[s];
        return result;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);