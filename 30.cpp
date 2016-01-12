#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
    	if(words.size() == 0) return result;
        int i = 0;
        int word_length = words[0].size();
        vector<int> transform;
        vector<bool> match;
        for(int j = 0; j < words.size(); j ++) {
        	match.push_back(false);
        }
        while(i < word_length) {
        	int pos = i;
        	//transform the string to a integer list
        	while(pos < s.size() - word_length + 1) {
        		string tmpword = s.substr(pos, word_length);
        		int j = 0;
        		for(; j < words.size(); j ++) {
	        		if(tmpword == words[j]) {
	        			transform.push_back(j);
	        			break;
	        		}
	        	}
	        	if(j == words.size()) transform.push_back(-1);
	        	pos += word_length;
        	}
//        	for(int n = 0; n < transform.size(); n ++) {
//        	    cout << transform[n] << " ";
//        	}
//        	cout << endl;
//        	//find the continious list that contains all the position in words
        	int index = 0;
        	int m = i;
        	int matched = 0;
        	vector<bool> tmpmatch = match;
        	while(m < transform.size()){
        		if(transform[m] == -1) {
        			m ++;
        			continue;
        		}
        		else {
        			if(tmpmatch[transform[m]]) {
        				m -= 1;
        				tmpmatch = match;
        				continue;
        			}
        			else {
        				index = m;
        				int matched = 0;
        				while(m < transform.size() && transform[m] != -1 && !tmpmatch[transform[m]] && matched < words.size()) {
        					m ++;
        					matched ++;
        				}
        				tmpmatch = match;
        				if(matched == words.size()) result.push_back(index+(i*word_length));
        				else m = index + 1;
        			}
        		}
    		}
        	transform.clear();
    		i ++;
    	}
    	return result;
    }
};
int main()
{
    Solution s;
    string str = "abababababab";
    string arr[2] = {"aba", "bab"};
    vector<string> strarr(arr, arr+2);
    vector<int> result = s.findSubstring(str, strarr);
    for(int i = 0; i < result.size(); i ++) cout << result[i] << " ";
}

