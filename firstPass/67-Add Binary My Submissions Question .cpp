class Solution {
public:
    string addBinary(string a, string b) {
        if(a == "" || a == "0") return b;
        if(b == "" || b == "0") return a;
        if(b.size() > a.size()) {
            string tmp = a;
            a = b;
            b = tmp;
        }
        bool flag = false;
        int i = a.size() - 1;
        int j = b.size() - 1;
        string result = "";
        while(j >= 0) {
            if(a[i] == '1' && b[j] == '1') {
                if(flag) {
                    result.insert(result.begin(), '1');
                    flag = true;
                }
                else {
                    result.insert(result.begin(), '0'); 
                    flag = true;
                }
            }
            else if(a[i] == '1' && b[j] == '0' || a[i] == '0' && b[j] == '1') {
                if(flag) {
                    result.insert(result.begin(), '0');
                    flag = true;
                }
                else result.insert(result.begin(), '1');
            }
            else {
                if(flag) {
                    result.insert(result.begin(), '1');
                    flag = false;
                }
                else result.insert(result.begin(), '0');
            }
            i --;
            j --;
        }
        if(i == j) {
            if(flag) result.insert(result.begin(), '1');
        }
        else {
            for(; i >= 0; i --) {
                if(a[i] == '1') {
                    if(flag) {
                        result.insert(result.begin(), '0');
                        flag = true;
                    }
                    else {
                        result.insert(result.begin(), '1');
                        flag = false;
                    }
                }
                else {
                    if(flag) {
                        result.insert(result.begin(), '1');
                        flag = false;
                    }
                    else {
                        result.insert(result.begin(), '0');
                        flag = false;
                    }
                }
            }
            if(flag) result.insert(result.begin(), '1');
        }
        return result;
    }
};