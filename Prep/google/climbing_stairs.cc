class Solution {
public:
    std::unordered_map<int, int> umap;
    int climbStairs(int n) {
        return _climb(n);
    }

    int _climb(int n) {
        if (n <= 3) return n;
        if (umap.count(n)) return umap[n];
        umap[n] = _climb(n - 1) + _climb(n - 2);
        return umap[n];
    }
};
