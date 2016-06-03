class Solution {
public:
    string reverseVowels(string s) {
        if(s.size() < 2) return s;
        string vowels = "";
        string result = "";
        for(int i = 0; i < s.size(); i ++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') vowels = s[i] + vowels;
        }
        int j = 0;
        for(int i = 0; i < s.size(); i ++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                result = result + vowels[j];
                j ++;
            }
            else result = result + s[i];
        }
        return result;
    }
};