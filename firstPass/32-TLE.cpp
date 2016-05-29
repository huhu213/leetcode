class Solution {
public:
    int longestValidParentheses(string s) {
    	if(s == "") return 0;
        int i = 0;
        int result = 0;
        int length = 0;
        stack<char> left;
        left.push('#');
        while(i < s.size()) {
        	int j = i;
        	while(j < s.size()) {
        		if(s[j] == '(') {
        			left.push('(');
        			j ++;
        		}
        		else {
        			if(left.top() == '(') {
        				left.pop();
        				length ++;
        				if(left.top() == '#') result = max(result, length*2);
        				j ++;
        			}
        			else {
        				i = j + 1;
        				length = 0;
        				result = max(result, length*2);
        				break;
        			}
        		}
        	}
        	if(j == s.size()) {
        	    if(left.size() == 1) {
        	        result = max(result, length*2);
        	        length = 0;
        	        if(i == 0) return result;
        	    }
        	    else {
        	        i ++;
        	        length = 0;
        	    }
        	}
        	left.empty();
        	left.push('#');
        }
        return result;
    }
};