class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        int st = 1;
        int p1 = intervals[0][0];
        int p2 = intervals[0][1];
        while (st < intervals.size()) {
            if (p2 >= intervals[st][0]) {
                p2 = max(p2, intervals[st][1]);
            } else {
                res.push_back({p1, p2});
                p1 = intervals[st][0];
                p2 = intervals[st][1];
            }
            st++;
        }
        res.push_back({p1, p2});
        return res;
    }
};
