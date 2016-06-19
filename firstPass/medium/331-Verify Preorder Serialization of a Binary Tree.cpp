class Solution {
public:
    bool isValidSerialization(string preorder) {
        int l = preorder.size();
        std::regex e("\\d+,#,#");
        while(std::regex_search(preorder,e)) {
            preorder = std::regex_replace(preorder,e,"#");
        }
        if(preorder == "#") return true;
        else return false;
    }
};