class Solution{
public:
	static bool cmp(pair<int, int> a, pair<int, int> b){
		if(a.first < b.first) return a < b;
		else if(a.first == b.first) return a == b;
		else return a > b;
	}
    vector<int> twoSum(vector<int>& nums, int target) {  
    	std::vector<int> result;
        int l = nums.size(); 
        if(l == 2){
        	result.push_back(1);
        	result.push_back(2);
        	return result;
        }
        vector<pair<int, int>> data;
        pair<int, int> temp(0,0);
        for(int i = 2; i < l; i ++){
            temp.first = nums[i];
            temp.second = i;
        	data.push_back(temp);
        }
        sort(data.begin(), data.end(), cmp);

        int head = 0;
        int tail = l-1;
        while(head <= tail){
        	if(data[head].first + data[tail].first == target){
				result.push_back(min(data[head].second+1,data[tail].second+1));
				result.push_back(min(data[head].second+1,data[tail].second+1));
				return result;
        	}
        	else if(data[head].first + data[tail].first > target){
        		tail --;
        	}
        	else{
        		head ++;
        	}
        }
    }
};	

