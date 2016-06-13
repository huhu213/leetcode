class Solution {
public:
    string getHint(string secret, string guess) {
    	int bulls = 0;
    	int cows = 0;
    	string result;
        if(secret == guess) {
        	bulls = secret.size();
        	stringstream ss;
        	ss << bulls;
        	string b;
        	ss >> b;
        	result = b + 'A' + '0' + 'B';
        	return result;
        }
        std::unordered_map<char, int> mp;
        for(int i = 0; i < secret.size(); i ++) {
        	if(mp.find(secret[i]) == mp.end()) mp[secret[i]] = 1;
        	else mp[secret[i]] ++;
        } 
        for(int i = 0; i < guess.size(); i ++) {
            if(secret[i] == guess[i]) {
                mp[secret[i]] --;
                bulls ++;
            }
        }
        for(int i = 0; i < guess.size(); i ++) {
            if(secret[i] == guess[i]) continue;
    		if(mp.find(guess[i]) != mp.end() && mp[guess[i]] > 0) {
    			cows ++;
    			mp[guess[i]] --;
    		}
        }
        stringstream ss;
        ss << bulls;
        string b;
        ss >> b;
        result = result + b + 'A';
        stringstream sss;
        sss << cows;
        string c;
        sss >> c;
        result = result + c + 'B';
        return result;
    }
};