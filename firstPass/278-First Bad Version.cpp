// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int judge(int l, int r) {
        int s = l, e = r;
        if(e <= s) return s;
        int m;
        if(s % 2 == 1 && e % 2 == 1) {
            s = s / 2;
            e = e / 2;
            m = s + e + 1;
        }
        else {
            s = s / 2;
            e = e / 2;
            m = s + e;
        }
        if(isBadVersion(m)) {
            if(m == 1) return m;
            else if(!isBadVersion(m-1)) return m;
            else return judge(s, m-1);
        }
        else return judge(m+1, r);
    }
    int firstBadVersion(int n) {
        if(n == 1 && isBadVersion(n)) return n;
        else return judge(1, n);
    }
};