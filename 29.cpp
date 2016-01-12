class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) return dividend;
        else if(divisor == -1) return -dividend;
        bool flag = false;
        if((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) flag = true;
        int result = 0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while(dividend >= divisor) {
            dividend -= divisor;
            result ++;
        }
        if(flag) {
            if(result > 2147483647) return 2147483647;
            else return result;
        }
        else {
            result = -result;
            if(result < -2147483648) return -2147483648;
            else return result;
        }
    }
};