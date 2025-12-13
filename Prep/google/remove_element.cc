class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int en = 0;
        for (int st = 0; st < nums.size(); st++) {
            if (nums[st] == val) continue;
            nums[en++] = nums[st];
        }
        return en;
    }
};
