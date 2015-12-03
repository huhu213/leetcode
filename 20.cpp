class Solution {
public:
	bool isValid(string s) {
		if (s == "" or s.size() == 1)
		{
			return false;
		}
		else
		{
			stack<char> v;
			int i = 0;
			int len = s.length();
			v.push('#');

			while(i < len)
			{
				while(s[i] == '(' or s[i] == '[' or s[i] == '{')
				{
					v.push(s[i]);
					i ++;
				}
				int j = v.size() - 1;
				if ((v.top() == '(' && s[i] == ')') or (v.top() == '[' && s[i] == ']') or (v.top() == '{' && s[i] == '}'))
				{
					v.pop();
					i ++;
				}
				else
				{
					return false;
				}
			}
			if (v.size() != 1)
			{
				return false;
			}
			return true;
		}
	}
};