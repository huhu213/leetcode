class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<string> v;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        if (digits == "")
        {
            return v;
        }
        else
        {

            std::vector<string> result;
            for (int i = 0; i < digits.length(); ++i)
            {
                v = result;
                result.clear();
                int v_len = v.size();
                int num = digits[i] - 48;
                int startIndex = (num) + (num-3)*2;
                int len = 0;
                string tempStr = "";
                if (num > 1)
                {
                    if (num == 7)
                    {
                        len = 4; 
                    }
                    else if(num == 8)
                    {
                        len = 3;
                        startIndex = (num) + (num-3)*2 + 1;
                    }
                    else if(num == 9)
                    {
                        len = 4;
                        startIndex = (num) + (num-3)*2 + 1;
                    }
                    else{
                        len = 3;
                    }
                    if (v_len == 0)
                    {
                        for (int k = 0; k < len; ++k)
                        {
                            result.push_back(alpha.substr(startIndex+k,1));
                        }
                    }
                    else
                    {
                        for (int j = 0; j < v_len; ++j)
                        {
                            for (int k = 0; k < len; ++k)
                            {
                                tempStr = v[j];
                                tempStr += (alpha.substr(startIndex+k,1));
                                result.push_back(tempStr);
                            }
                        }
                    }
                }
            }
            return result;
        }
    }
};