class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() == 0) return result;
        vector<string> single;
        single.push_back(strs[0]);
        result.push_back(single);
        std::unordered_map<string, int> matchTable;
        string firstStr = strs[0];
        sort(firstStr.begin(), firstStr.end());
        matchTable[firstStr] = 1;
        for(int i = 1; i < strs.size(); i ++) {
            string curStr = strs[i];
            sort(curStr.begin(), curStr.end());
            int j = 0;
            if(matchTable.find(curStr) != matchTable.end()) {
                result[matchTable[curStr]-1].push_back(strs[i]);
                sort(result[matchTable[curStr]-1].begin(), result[matchTable[curStr]-1].end());
                break;
            }
            else{
                vector<string> tmp;
                tmp.push_back(strs[i]);
                result.push_back(tmp);
                matchTable[curStr] = result.size();
            }
        }
        return result;
    }
};