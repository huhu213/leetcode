class Solution {
public:
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
        for(int i = 0; i < l; i ++) {
            stringstream ss;
            string s;
            ss << nums[i];
            ss >> s;
            str.push_back(s);
        }
        sort(str.begin(), str.end());
        for(int i = l-2; i >= 0; i --) {
            if(str[i].size() >= str[i+1].size()) continue;
            else {
                string tmp = str[i];
                int j = i + 1;
                while((j < l) && (tmp.size() < str[j].size()) && (tmp+str[j] >= str[j]+tmp)) {
                    str[j-1] = str[j];
                    j ++;
                }
                str[j-1] = tmp;
            }
        }
        for(int i = l-1; i >= 0; i --) {
            result += str[i];
        }
        if(result[0] == '0') result = "0";
        return result;
    }
};