class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.size() == 0) return result;
        int i = 0;
        int word_length = words[0].size();
        vector<int> transform;
        vector<bool> match;
        for(int j = 0; j < words.size(); j ++) {
            match.push_back(false);
        }
        map<int, bool> resultmap;
        while(i < s.size() - word_length + 1) {
            int pos = i;
            //transform the string to a integer list
            while(pos < s.size() - word_length + 1) {
                string tmpword = s.substr(pos, word_length);
                int j = 0;
                for(j = 0; j < words.size(); j ++) {
                    if(tmpword == words[j]) {
                        transform.push_back(j);
                        break;
                    }
                }
                if(j == words.size()) transform.push_back(-1);
                pos += word_length;
            }
//          //find the continious list that contains all the position in words
            int index = 0;
            int m = 0;
            int matched = 0;
            vector<bool> tmpmatch = match;
            while(m < transform.size()){
                index = m;
                tmpmatch = match;
                if(transform[m] == -1) {
                    m ++;
                    continue;
                }
                else {
                    if(tmpmatch[transform[m]]) {
                        continue;
                    }
                    else {
                        int matched = 0;
                        while(m < transform.size() && transform[m] != -1 && !tmpmatch[transform[m]] && matched < words.size()) {
                            tmpmatch[transform[m]] = true;
                            m ++;
                            matched ++;
                        }
                        if(matched == words.size()){
                            if(resultmap.find(index*3+i) == resultmap.end()) {
                                resultmap[index*3+i] = true;
                                result.push_back(index*3+i);
                            }
                        }
                    }
                }
                m = index + 1;
            }
            transform.clear();
            i ++;
        }
        return result;
    }
};