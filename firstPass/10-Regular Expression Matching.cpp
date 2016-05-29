class Solution {
public:
    bool isMatch(string s, string p) {
        if(s == p) return true;
        if(p == "") return s == "" ? true : false;
        if(p == "*") return true;
        if(p == ".") return s.size() == 1 ? true : false;
        if(p.size() == 1) {
            if(s.size() != 1) return false;
            if(s.size() == 1 && s != p) return false;
        }
        int i = p.size()-1;
        int j = s.size()-1;
        if(p[i] == '*') {
            while(i >= 0 && p[i] == '*') i --;
            if(i == 0) return true;
            for(int t = 1; t <= s.size(); t ++) {
                string tmp = s.substr(0, t);
                if(isMatch(tmp, p.substr(0, i))) return true;
            }
            return false;
        }
        else if(p[i] == '.') return isMatch(s.substr(0, j), p.substr(0, i));
        else {
            if(s[j] == p[i]) {
               return isMatch(s.substr(0, j), p.substr(0, i));
            }
            else return false;
        }
    }
};