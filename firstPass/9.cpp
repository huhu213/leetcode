class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        else
        {
            if (x < 10)
            {
                return true;
            }
            else
            {
                int y = x;
                int decimal = 1;
                while(y >= 10)//这个地方卡了很久，注意边界条件
                {
                    y /= 10;
                    decimal *= 10;
                }
                y = x;
                int current_decimal = decimal;
                int next_decimal = decimal / 10;
                cout << current_decimal << endl;
                while(next_decimal > 0)
                {
                    if(y == 0)
                    {
                        return true;
                    }
                    cout << y << endl;
                    if((y / current_decimal) == (y % 10))
                    {
                        y = y % current_decimal;
                        y -= (y % 10);
                        y /= 10;
                        cout << y << endl;
                        current_decimal = next_decimal / 10;
                        next_decimal = current_decimal / 10;
                    }
                    else
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }
};