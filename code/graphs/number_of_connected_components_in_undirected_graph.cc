// approach : use union find
// to calculate the number of
// components use find and
// add the parent to set;
//
// time : O(n * alpha(n)) space : O(n)

class Solution {
public:
    std::vector<int> parent;
    std::vector<int> size;
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_set<int> res;
        parent = vector<int>(n, 0);
        size = vector<int>(n, 0);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        for (auto e : edges) _union(e[0], e[1]);
        for (int i = 0; i < n; i++) res.insert(_find(i));

        return res.size();
    }

    int _find(int x) {
        if (x != parent[x]) x = _find(parent[x]);
        return parent[x];
    }

    void _union(int x, int y) {
        x = _find(x);
        y = _find(y);
        if (x == y) return;
        if (size[x] > size[y]) {
            size[x] += size[y];
            parent[y] = x;
        } else {
            size[y] += size[x];
            parent[x] = y;
        }
    }
};
