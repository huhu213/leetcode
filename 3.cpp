#include <iostream>
#include <vector>

using namespace std;

    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            std::vector<int> loc;
            std::vector<int> last_loc;
            std::vector<int> result;

            for (int i = 0; i < 128; ++i)
            {
                last_loc.push_back(-1);
            }

            if (s == "")
            {
                return 0;
            }
            else
            {
                for(int i = 0; i < s.length(); i++){
                    int index = int(s[i]) - 32;
                    if (last_loc[index] == -1)
                    {
                        last_loc[index] = i;
                        loc.push_back(-1);
                    }
                    else{
                        loc.push_back(last_loc[index]);
                        last_loc[index] = i;
                    }
                }

                result.push_back(1);
                int max_length = 1;

                for (int j = 1; j < s.length(); j++)
                {
                    if (loc[j] == -1)
                    {
                        result.push_back(result[j-1]+1);
                    }
                    else{
                        if(loc[j] >= j-result[j-1]){
                            result.push_back(j-loc[j]);
                        }
                        else
                        {
                            result.push_back(result[j-1]+1);
                        }

                    }
                    cout << result[j] << endl;
                    max_length = max(max_length, result[j]);
                }
                return max_length;
            }

        }
    };

int main(){
    string str = "au";
    Solution s;
    cout << s.lengthOfLongestSubstring(str);
}
