class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> umap;
        int max_len = 0;
        int st = 0;
        int en = 0;
        while (en < s.size()) {
            umap[s[en]]++;
            while (st < en && umap[s[en]] > 1) {
                umap[s[st]]--;
                st++;
            }
            max_len = max(max_len, (en - st) + 1);
            en++;
        }
        return max_len;
    }
};
