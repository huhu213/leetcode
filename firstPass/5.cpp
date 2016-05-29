class Solution {
public:
    string longestPalindrome(string s) {
    	int len = s.length();
        std::vector<char> v;
        int index = 0;

        int loc = 0;

        if(len == 0){
            return "";
        }
        else if(len == 1){
            return s;
        }
        for (int i = 0; i < 2*len+1; ++i)
        {
        	if (i % 2  == 1)
        	{
        		v.push_back(s[(i-1)/2]);
        	}
        	else{
        		v.push_back('*');
        	}
        }
        int max_length = 1;
        int pa_length = max_length;

        for (int i = 1; i < 2*len; i++)
        {
        	index = 1;
        	int left = i - index;
        	int right = i + index;
        	if(i <= len){
        	    pa_length = 1;
        		while(left >= 0){
	        		if (v[left] == v[right])
	        		{
	        			index ++;
	        			pa_length += 2;
	        			if(pa_length >= max_length){
                            loc = i;
                            max_length = pa_length;
	        			}

	        			left = i - index;
	        			right = i + index;
	        		}
	        		else{
	        			pa_length = 1;
	        			break;
	        		}
	        	}
        	}
        	else{
        		pa_length = 1;
        		while(right <= 2*len){
	        		if (v[left] == v[right])
	        		{
	        			index ++;
	        			pa_length += 2;
	        			if(pa_length >= max_length){
                            loc = i;
                            max_length = pa_length;
	        			}

	        			left = i - index;
	        			right = i + index;
	        		}
	        		else{
	        			pa_length = 1;
	        			break;
	        		}
	        	}
        	}
        }
        cout << loc <<endl;

        if(loc % 2 == 0){
            index = (max_length - 1)/2;
            index = index / 2;
            loc = loc / 2;
            string result = s.substr(loc-index, 2*index);
            return result;
        }
        else{
            index = (max_length - 1)/2;
            index = index / 2;
            loc = (loc-1)/2;
            string result = s.substr(loc-index, 2*index+1);
            return result;
        }
    }
};