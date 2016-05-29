class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0) return word2.size();
        if(word2.size() == 0) return word1.size();
        std::vector<std::vector<int>> distance;
        int m = word1.size();
        int n = word2.size();
        for(int i = 0; i < m; i ++) {
            distance.push_back(std::vector<int>(n, 0));
        }
        if(word1[0] == word2[0]) distance[0][0] = 0;
        else distance[0][0] = 1;
        for(int i = 1; i < n; i ++) {
            if(word1[0] == word2[i]) distance[0][i] = i;
            else distance[0][i] = distance[0][i-1]+1;
        }
        for(int j = 1; j < m; j ++) {
            if(word1[j] == word2[0]) distance[j][0] = j;
            else distance[j][0] = distance[j-1][0]+1;
        }
        for(int i = 1; i < m; i ++) {
            for(int j = 1; j < n; j ++) {
                if(word1[i] == word2[j]) distance[i][j] = distance[i-1][j-1];
                else {
                    distance[i][j] = min(min(distance[i-1][j], distance[i][j-1]), distance[i-1][j-1])+1;
                }
            }
        }
        return distance[m-1][n-1];
    }
};