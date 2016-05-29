class Solution {
public:
    string convert(string s, int numRows) {
    	int len = s.length();
        int col = len / numRows;
        std::vector<char> v;

        if(len  == 0)
        {
        	return "";
        }
        else if(len  == 1)
        {
        	return s;
        }

        for (int i = 0; i < numRows; ++i)
        {
        	int currentIndex = i;
        	int nextIndex = 0;
        	int gap = numRows + numRows - 2;

        	if (i == 0 or i == (numRows-1))
        	{
        		while(currentIndex < len){
        			v.push_back(s[currentIndex]);
        			currentIndex += gap;
        		}	
        	}
        	else
        	{
        		while(currentIndex < len)
        		{
        			v.push_back(s[currentIndex]);
        			nextIndex = currentIndex + gap - 2*i;
        			if(nextIndex < len)
        			{
        				v.push_back(s[nextIndex]);
        			}
        			currentIndex = currentIndex + gap;
        		}
        	}
        }

		string result = "";
        for (int i = 0; i < len; ++i)
        {
        	result += v[i];
        } 

        return result;
};