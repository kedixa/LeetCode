class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> edge(n);
        vector<int> in(n, 0);
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
            for(const auto &to : edge[p]) {
                --in[to];
                if(in[to] == 0) que.push(to);
            }
        }
        for(int i = 0; i < n; ++i)
            if(in[i]) return false;
        return true;
    }
};
