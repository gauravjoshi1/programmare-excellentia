class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int st = 0; st < nums.size(); st++) {
            if (st > 0 && nums[st] == nums[st - 1]) continue;
            two_sum(nums, st, res);
        }
        return res;
    }

    void two_sum(vector<int>& nums, int start, vector<vector<int>>& res) {
        int st = start + 1;
        int en = nums.size() - 1;
        while (st < en) {
            int sum = nums[start] + nums[st] + nums[en];
            if (sum == 0) {
                res.push_back({nums[start], nums[st], nums[en]});
                st++;
                en--;
                while (st < en && nums[st] == nums[st - 1]) st++;
            } else if (sum > 0) en--;
            else st++;
        }
    }
};
