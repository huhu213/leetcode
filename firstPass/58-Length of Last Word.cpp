class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s == "") return 0;
        int length = s.size();
        int i = length - 1;
        while(i >= 0 && s[i] == ' ') i --;
        if(i < -1) return 0;
        int count = 0;
        while(i >= 0 && s[i] != ' '){
            count ++;
            i --;
        } 
        return count;
    }
};