class Solution{
public:
	int RomanToInteger(string str){
		std::map<char, int> roman;
		roman['I'] = 1;
		roman['V'] = 5;
		roman['X'] = 10;
		roman['L'] = 50;
		roman['C'] = 100;
		roman['D'] = 500;
		roman['M'] = 1000;

		int len = str.size();
		if (len == 1)
		{
			return roman[str[0]];
		}

		int currentIndex = len-1;
		int prevIndex = 0;
		int result = 0;

		while(prevIndex >= 0)
		{
			prevIndex = currentIndex - 1;
			if (roman[str[currentIndex]] > roman[str[prevIndex]])
			{
				result += (roman[str[currentIndex]] - roman[str[prevIndex]]);
				currentIndex -= 2;
			}
			else if(roman[str[currentIndex]] == roman[str[prevIndex]])
			{
				result += (roman[str[currentIndex]] + roman[str[prevIndex]]);
				currentIndex -= 2;
			}
			else
			{
				result += roman[str[currentIndex]];
				currentIndex = prevIndex;
				prevIndex = prevIndex - 1;
			}
		}

		if (prevIndex == -1)
		{
			result += roman[str[currentIndex]];
		}

		return result;
	}
};