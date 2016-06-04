class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 0) return false;
        if(num % 4 == 1) return false;
        num = num/4;
        if(num == 1) return true;
        else return isPowerOfFour(num);
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        if(((num & (num-1)) == 0) && (num & 0x55555555) != 0) return true;
        else return false;
    }
};

//2的幂次肯定是1000000...00的格式，因此和num-1，即011111...111与的结果一定为0
//4的幂次是2的偶数次幂，对于32位数来说，一定是0101 0101 0101 0101 0101 0101 0101 0101中的某一位，因此只要保证和0x55555555相与结果不为0即可