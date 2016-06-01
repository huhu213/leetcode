class Solution {
public:
	void insert(int loc, vector<string>& str, string s) {
		if(loc == str.size()) str.push_back(s);
		else {
			str.push_back(s);
			for(int i = s.size()-1; i > loc; i --) {
				str[i] = str[i-1];
			}
			str[loc] = s;
		}
	}
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return "";
        string result;
        if(nums.size() == 1) {
        	stringstream ss;
        	ss << nums[0];
        	ss >> result;
        	return result;
        }
        int l = nums.size();
        vector<string> str;
        stringstream s1;
        s1 << nums[0];
        s1 >> result;
        str.push_back(result);
        for(int i = 1; i < l; i ++) {
            stringstream ss;
        	string s;
        	ss << nums[i];
        	ss >> s;
        	if(nums[i] == 0) str.push_back(s);
        	else {
        		int j = 0;
        		for(; j < str.size(); j ++) {
        			if(str[j].size() <= s.size()) {
        				if(str[j] >= s) continue;
        				else break;
        			else {
        				if(sr[j] >= s) continue;
        				else break;
        			}
        		}
    			if(j == str.size()) str.push_back(s);
    			else {
    				if(str[j] + s >= s + str[j]) str.insert(j+1, s);
    				else str.insert(j, s);
    			}
        	}
        }
        return result;
    }
};