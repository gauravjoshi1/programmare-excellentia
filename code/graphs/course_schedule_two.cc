// approach : use topological sort
// and while doing that keep
// track of the node being
// popped from queue and push
// to res;
//
// time : O(n), space : O(n)


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> res;
        std::unordered_map<int, vector<int>> umap;
        std::vector<int> in(numCourses, 0);
        for (vector<int>& pre : prerequisites) {
            umap[pre[1]].push_back(pre[0]);
            in[pre[0]]++;
        }
        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (int nei : umap[curr]) {
                in[nei]--;
                if (in[nei] == 0) q.push(nei);
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (in[i] != 0) return {};
        }

        return res;
    }
};
