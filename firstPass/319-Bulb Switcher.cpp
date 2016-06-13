class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;
       int index = 1;
       int gap = 2 * index + 1;
       while(gap < n) {
           index ++;
           gap += 2 * index + 1;
       }
       return index;
    }
};