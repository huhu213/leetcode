class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result;
        if(words.size() == 0) return result;
        int wordLength = words[0].size();
        int wordNum = words.size();
        if(wordNum * wordLength > s.size()) return result;
        int totalLength = wordNum * wordLength;
        if(s.size() < wordNum) return result;
        std::unordered_map<string, int> mp;
        for(int i = 0; i < words.size(); i ++) {
            if(mp.find(words[i]) == mp.end()) mp[words[i]] = 1;
            else mp[words[i]] += 1;
        }
        for(int i = 0; i <= s.size() - totalLength; i ++) {
            string curstr = s.substr(i, wordLength);
            if(mp.find(curstr) == mp.end()) continue;
            else {
                mp[curstr] -= 1;
                int j = i + wordLength;
                int count = 1;
                while(j < s.size() && count < wordNum) {
                    string nextStr = s.substr(j, wordLength);
                    if(mp.find(nextStr) == mp.end()) break;
                    else if(mp[nextStr] == 0) break;
                    else {
                        mp[nextStr] -= 1;
                        count ++;
                        j += wordLength;
                    }
                }
                if(count == wordNum) result.push_back(i);
                if(s.size()-i == totalLength) return result;
            }
             	mp.clear();
             	for(int t = 0; t < words.size(); t ++) {
                 	if(mp.find(words[t]) == mp.end()) mp[words[t]] = 1;
                 	else mp[words[t]] += 1;
                 }
        }
        return result;
    }
};