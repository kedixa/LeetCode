class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // 简单的拓扑排序问题
		int n = numCourses;
        vector<vector<int>> edge(n);
        vector<int> in(n, 0);
        vector<int> order;
        for(const auto &p : prerequisites) {
            edge[p.second].push_back(p.first);
            ++in[p.first];
        }
        queue<int> que;
        for(int i = 0; i < n; ++i) {
            if(in[i] == 0) que.push(i);
        }
        while(!que.empty()) {
            int p = que.front();
            que.pop();
            order.push_back(p);
            for(const auto &to : edge[p]) {
                --in[to];
                if(in[to] == 0) que.push(to);
            }
        }
        if(order.size() != n) return {};
        else return order;
    }
};
