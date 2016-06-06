class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() != s.size()) return false;
        std::unordered_map<char, int> mps;
        std::unordered_map<char, int> mpt;
        for(int i = 0; i < s.size(); i ++) {
            if(mps.find(s[i]) == mps.end()) mps[s[i]] = 1;
            else mps[s[i]] ++;
            if(mpt.find(t[i]) == mpt.end()) mpt[t[i]] = 1;
            else mpt[t[i]] ++;
        }
        if(mps.size() != mpt.size()) return false;
        else {
            std::unordered_map<char, int>::iterator its;
            for(its = mps.begin(); its != mps.end(); its ++) {
                if(mpt[its->first] != its->second) return false;
            }
            return true;
        }
    }
};