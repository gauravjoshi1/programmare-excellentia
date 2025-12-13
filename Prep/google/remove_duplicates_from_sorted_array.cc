class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int st = 0;
        int en = 0;
        while (en < nums.size()) {
            int val = nums[en];
            while ((en < nums.size()) && (val == nums[en])) en++;
            nums[st++] = val;
        }
        return st;
    }
};
