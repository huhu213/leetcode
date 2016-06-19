/*
简单的方法是O(n^2)，对每个元素都进行一次循环
但是可以看到，若在位置t不能走到下一个站点，则结果一定在t位置之后。
证明用反证法：
1. 假设从g0开始，到gt时，g0-c0 + g1-c1 + ... + gt-ct < 0;
2. 则起始位置一定在t之后，因为此时t位置gt-ct，不能作为起始位置;
3. 而对于任意i，0 < i <= t-1，若从位置i开始，能到位置t，则表示gi-ci + gi+1 - ci+1 + ... + gt - ct >= 0，而由
(1)可知， g1-c1 + g2-c2 + ... + gi-1-ci-1 + (gi-ci + gi+1 - ci+1 + ... + gt - ct) < 0, 而假设中由位置0
可以到达位置i，则g1-c1 + g2-c2 + ... + gi-1-ci-1 > 0, 因此g1-c1 + g2-c2 + ... + gi-1-ci-1 + (gi-ci + gi+1 - ci+1 + ... + gt - ct) > 0;
与假设矛盾，因此假设不成立；
即，结果一定在位置t之后。
total变量用于判断位置t之后的起始站能不能到达终点，因为要保证从位置s, t < s < n, gs-cs + ... + gn-1-cn-1 > g0-c0 + g1-c1 + ... + gs-1-cs-1
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int left = 0;
        int total = 0;
        int s = 0;
        for(int i = 0; i < gas.size(); i ++) {
            left += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(left < 0) {
                s = i + 1;
                left = 0;
            }
        }
        if(total >= 0) return s;
        else return -1;
    }
};

