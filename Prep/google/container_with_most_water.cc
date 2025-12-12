class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0;
        int en = height.size() - 1;
        int max_water = 0;
        while (st < en) {
            max_water = max(max_water, ((en - st) * min(height[en], height[st])));
            if (height[st] < height[en]) st++;
            else en--;
        }
        return max_water;
    }
};
