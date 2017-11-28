class Solution {
    vector<vector<int>> e;
    vector<int> pre;
    int n;
    int bfs(int k) {
        vector<int> flag(n, 0);
        vector<int> dist(n, n+1);
        pre.clear();
        pre.resize(n, -1);
        queue<int> que;
        que.push(k);
        flag[k] = true;
        dist[k] = 0;
        while(!que.empty()) {
            int q = que.front();
            que.pop();
            for(int i = 0; i < e[q].size(); i++) {
                int &p = e[q][i];
                if(flag[p] == 0) {
                    que.push(p);
                    flag[p] = 1;
                    dist[p] = dist[q] + 1;
                    pre[p] = q;
                }
            }
        }
        int idx = k;
        for(int i = 0; i < n; i++)
            if(dist[i] > dist[idx])
                idx = i;
        return idx;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        // 先（两边bfs）找树的直径，然后取直径中间位置
        e.clear();
        e.resize(n);
        for(const auto &p : edges) {
            e[p.first].push_back(p.second);
            e[p.second].push_back(p.first);
        }
        this->n = n;
        int p = bfs(0);
        p = bfs(p);
        vector<int> path;
        while(p != -1) {
            path.push_back(p);
            p = pre[p];
        }
        int len = path.size();
        if(len % 2 == 1)
            return {path[len/2]};
        else return {path[len/2-1], path[len/2]};
    }
};
