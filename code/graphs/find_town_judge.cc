// can be solved using indegree and outdegree
// concept, indegree number of edges coming
// in, outdegree number of edges going out
// calculate both and check if a node
// has outdegree as 0 and indegree
// as from all nodes except self
// is the answer.
//
//
// method 2 : form a graph and
// basiccally check the same thing 
// that is number of edges emerging
// out from a node is 0 and each node
// is connected to it
//
//
// time : O(n), space : O(n)


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // std::unordered_map<int, std::unordered_map<int, bool>> umap;
        // for (int i = 0; i < trust.size(); i++) umap[trust[i][0]][trust[i][1]] = true;
        // int res = -1;
        // for (int i = 1; i <= n; i++) {
        //     if (umap[i].size() == 0) {
        //         res = i;
        //         break;
        //     }
        // }

        // for (int i = 1; i <= n; i++) {
        //     if (i != res && !umap[i][res]) return -1;
        // }
        // return res;

        // using indegree and outdegree concept
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);
        for (int i = 0; i < trust.size(); i++) {
            indegree[trust[i][1]]++;
            outdegree[trust[i][0]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (outdegree[i] == 0 && indegree[i] == n - 1) return i;
        }
        return -1;
    }
};
