class Solution {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res(2);
        int n = edges.size();
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        for (vector<int>& e : edges) {
            if (!_union(e[0], e[1])) {
                res[0] = e[0];
                res[1] = e[1];
            }
        }

        return res;
    }

    int _find(int x) {
        if (x != parent[x]) x = _find(parent[x]);
        return parent[x];
    }

    bool _union(int x, int y) {
        x = _find(x);
        y = _find(y);
        if (x == y) return false;
        if (size[x] > size[y]) {
            size[x] += size[y];
            parent[y] = x;
        } else {
            size[y] += size[x];
            parent[x] = y;
        }
        return true;
    }
};
