class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& div) {
        div[node] = 0;
        for (int i = 0; i < adj[node].size(); i++) {
            int nxt = adj[node][i];
            if (div[nxt] == 1) {
                dfs(nxt, adj, div);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < invocations.size(); i++) {
            int a = invocations[i][0];
            int m = invocations[i][1];
            adj[a].push_back(m);
        }
        vector<int> div(n, 1);
        dfs(k, adj, div);
        for (int i = 0; i < invocations.size(); i++) {
            int a = invocations[i][0];
            int m = invocations[i][1];
            if (div[a] == 1 && div[m] == 0) {
                vector<int> ans;
                for (int j = 0; j < n; j++)
                    ans.push_back(j);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (div[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};