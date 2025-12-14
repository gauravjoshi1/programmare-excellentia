class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> umap(nums.begin(), nums.end());
        int max_cnt = 0;
        for (int num : umap) {
            int val = num;
            if (!umap.count(val - 1)) {
                int cnt = 1;
                while (umap.count(val + 1)) {
                    cnt++;
                    val++;
                }
                max_cnt = max(max_cnt, cnt);
            }
        }
        return max_cnt;
    }
};
