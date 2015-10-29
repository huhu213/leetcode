class Solution {
public:
    int myAtoi(string str) {
        if (str == "")
        {
        	return 0;
        }
        else
        {
        	int i = 0;
        	int len = str.length();
        	while(str[i] == 32)
        	{
        		i ++;
        	}
        	if (i == len)
        	{
        		return 0;
        	}
        	else
        	{
        		bool isMinus = false;
        		std::vector<int> v;
        		if (str[i] == 45)
        		{
        			isMinus = true;
        			i ++;
        		}
        		else if (str[i] == 43)
        		{
        			isMinus = false;
        			i ++;
        		}
        		while(i < len)
        		{
        			if(str[i] >= 48 && str[i] <= 57)
        			{
        				v.push_back(str[i]-48);
        				i ++;
        			}
        			else
        			{
        				break;
        			}
        		}
        		long decimal = 1;
        		long result = 0;
        		int length = v.size();
        		if(length > 10)
        		{
        		    if(isMinus)
        		    {
        		        return -2147483648;
        		    }
        		    else
        		    {
        		        return 2147483647;
        		    }
        		}
        		for (int i = length-1; i >= 0; i--)
        		{
        			result += v[i] * decimal;
        			decimal *= 10;
        		}
        		if(isMinus)
        		{
        			if(result > 2147483648)
        			{
        				return -2147483648;
        			}
        			else
        			{
        				return -result;
        			}
        		}
        		else
        		{
        			if(result > 2147483647)
        			{
        				return 2147483647;
        			}
        			else
        			{
        				return result;
        			}
        		}
        	}
        }
    }
};