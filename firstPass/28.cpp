class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_haystack = haystack.size();
        int len_needle = needle.size();
        int i = 0;
        int j = 0;
        while(i < len_haystack && j < len_needle) {
            if(haystack[i] == needle[j]) {
                i ++;
                j ++;
            }
            else {
                i = i - j + 1;
                j = 0;
            }
        }
        if(j == len_needle) return i - j;
        else return -1;
    }
};