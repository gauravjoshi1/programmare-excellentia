class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            if (umap.count(target - nums[i])) return {i, umap[target - nums[i]]};
            umap[nums[i]] = i;
        }
        return {-1, -1};
    }
};
