class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int max_right = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                max_right = i;
                break;
            }
        }
        if (max_right == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[max_right]) {
                swap(nums[i], nums[max_right]);
                break;
            }
        }

        reverse(nums.begin() + max_right + 1, nums.end());
    }
};
