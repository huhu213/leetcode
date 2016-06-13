class Solution {
public:
	int generate(int n, std::vector<int>& nums) {
		int count = 9;
		int digit = 9;
		for(int i = 1; i < n; i ++) {
			count *= digit;
			digit -= 1;
		}
		if(nums[n-2] == -1) nums[n-2] = generate(n-1, nums);
		count += nums[n-2];
		return count;
	}
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        std::vector<int> nums(n, -1);
        nums[0] = 10;
        return generate(n, nums);
    }
};