class Solution {
public:
    int reverse(int x) {
        int isMinus = false;
        vector<int> v;
        if(x < 0)
        {
            //转换后会溢出，需要提前判断
            if(x == -2147483648)
            {
                return 0;
            }
            else
            {
                isMinus = true;
                x = -x;
            }
        }
        if(x < 10)
        {
            if(isMinus)
            {
                return -x;
            }
            else return x;
        }
        {
            long decimal = 1;//由于循环中decimal的值多计算了一次，超出了int整数32位的范围，所以需要存储为long型
            int temp = x;
            int remainder = 0;

            while(temp > 0)
            {
                remainder = temp % 10;
                v.push_back(remainder);
                temp -= remainder;
                temp = temp / 10;
                decimal *= 10;
            }

            int len = v.size();
            long result = 0;//转换后的结果很可能就超出了int的范围，因此需要存储为long型
            decimal /= 10;

            for(int i = 0; i < len; i ++)
            {
                result = result + v[i] * decimal;
                decimal /= 10;
            }


            if (result > 2147483648)
            {
                return 0;
            }
            else
            {
                return isMinus ? -result : result;
            }
        }
    }
};