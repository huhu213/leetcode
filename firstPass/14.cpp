class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	int index = 1;
    	if (strs.size() == 0)
    	{
    		return "";
    	}
    	else if (strs[0] == "")
    	{
    		return "";
    	}
    	else{
    		string result = "";
    		result += strs[0][0];
    		while(true){
    			for (int i = 0; i < strs.size(); ++i)
    			{
    				if (strs[i] == "")
    				{
    					return "";
    				}
    				else if (strs[i].size() < index)
    				{
    					int len = result.size();
    					result = result.substr(0, len-1);
    					return result;
    				}
    				else if (strs[i][index-1] != result[index-1])
    				{
    					int len = result.size();
    					result = result.substr(0, len-1);
    					return result;
    				}
    			}
    			index += 1;
    			if (strs[0].size() < index)
    			{
    				return result;
    			}
    			else{
    				result += strs[0][index-1];
    			}
    		}
    	}
    }
};