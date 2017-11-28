class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n < 1) return 0;
        vector<long long> v(n);
        vector<int> cnt(primes.size(), 0);
        v[0] = 1;
        using Node = pair<long long, int>;
        priority_queue<Node, vector<Node>, greater<Node>> que;
        for(int i = 0; i < primes.size(); i++) {
            que.push({primes[i], i});
        }
        for(int i = 1; i < n; i++) {
            Node q = que.top();
            que.pop();
            if(v[i-1] == q.first) {
                i--;
            }
            else v[i] = q.first;
            cnt[q.second]++;
            q.first = primes[q.second] * v[cnt[q.second]];
            que.push(q);
        }
        return v.back();
    }
};
