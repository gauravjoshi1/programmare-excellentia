// union find
// create array to keep track
// of parent and size
//
// a graph will be a valid tree
// if all the nodes are connected
// and there are no cycles
// 
// time : O(n * alpha(n)), space : O(n)


class Solution {
public:
    vector<int> parent;
    vector<int> size;
    bool validTree(int n, vector<vector<int>>& edges) {
        parent = vector<int>(n, 0);
        size = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    
        for (auto e : edges) {
            if (!_union(e[0], e[1])) return false;
        }
        for (int i = 1; i < n; i++) {
            if (_find(0) != _find(i)) return false;
        }
        return true;
    }

    int _find(int x) {
        if (x != parent[x]) parent[x] = _find(parent[x]);
        return parent[x];
    }

    bool _union(int x, int y) {
        x = _find(x);
        y = _find(y);
        if (x == y) return false;
        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
        return true;
    }
};
