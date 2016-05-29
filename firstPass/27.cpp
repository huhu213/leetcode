class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return -1;
        else if(needle.size() > haystack.sieze()) return -1;
        else {
            int i = 0;
            int j = 0;
            int index = 0;
            int len_haystack = haystack.size();
            int len_needle = needle.size();
            while(i < len_haystack) {
                index = i;
                while(i < len_haystack && haystack[i] == needle[j]) {
                    i ++;
                    j ++;
                }
                if(j < len_needle) {
                    i = index + 1;
                    j = 0;
                }
                else return index;
            }
            return -1;
        }
    }
};