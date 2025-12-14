class Solution {
public:
    int ind = 0;
    string decodeString(string s) {
        return dfs(s);
    }

    string dfs(string& s) {
        if (ind == s.size()) return "";
        string res = "";
        while (ind < s.size() && s[ind] != ']') {
            if (!isdigit(s[ind])) {
                res += s[ind];
                ind++;
            } else {
                int val = 0;
                while (ind < s.size() && isdigit(s[ind])) {
                    val = (val * 10) + (s[ind] - '0');
                    ind++;
                }
                ind++; // [
                string st = dfs(s);
                ind++; // ]
                for (int i = 0; i < val; i++) res += st;
            }
        }
        return res;
    }
};
