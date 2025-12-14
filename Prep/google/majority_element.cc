class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int cnt = 0;
        // int cand;
        // for (int& num : nums) {
        //     if (cnt == 0) cand = num;
        //     cnt += (num == cand) ? 1 : -1;
        // }
        // return cand;

        int n = nums.size();
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int bit = 1 << i;
            int bit_cnt = 0;
            for (int& num : nums) {
                if (num & bit) bit_cnt++;
                if (bit_cnt > n / 2) result |= bit;
            }
        }

        return result;
    }
};
