class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::unordered_map<char, string> mp;
        std::unordered_set<string> strset;
        int i = 0;
        for(; i < pattern.size() && str != ""; i ++) {
            int loc = str.find(' ');
            string word;
            if(loc == -1) {
                word = str;
                str = "";
            }
            else {
                word = str.substr(0, loc);
                str = str.substr(loc+1);
            }
            if(strset.find(word) == strset.end()) strset.insert(word);
            // cout << loc << '&' << word << '&' << str << endl;
            if(mp.find(pattern[i]) == mp.end()) {
                mp[pattern[i]] = word;
            }
            else {
                if(mp[pattern[i]] == word) continue;
                else return false;
            }
        }
        if(str == "" && i != pattern.size()) return false;
        if(str != "" && i == pattern.size()) return false;
        if(strset.size() != mp.size()) return false;
        else return true;
    }
};