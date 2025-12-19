class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::unordered_map<int, std::unordered_map<int, bool>> umap;
        for (int i = 0; i < trust.size(); i++) umap[trust[i][0]][trust[i][1]] = true;
        int res = -1;
        for (int i = 1; i <= n; i++) {
            if (umap[i].size() == 0) {
                res = i;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (res != i && !umap[i][res]) return -1;
        }
        return res;
    }


};
