class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string t = "";
            for (int j = 0; j < min(common.size(), strs[i].size()); j++) {
                if (common[j] != strs[i][j]) break;
                t += strs[i][j];
            }
            if (t.size() < common.size()) common = t;
        }
        return common;
    }
};
