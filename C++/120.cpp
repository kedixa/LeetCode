class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        vector<long long> res(sz, (long long)numeric_limits<int>::max());
        res[0] = triangle[0][0];
        for(int i = 1; i < sz; i++)
        {
            auto &tri = triangle[i];
            res[i] = tri[i] + res[i-1];
            for(int j = i-1; j > 0; j--)
                res[j] = min(res[j], res[j-1]) + tri[j];
            res[0] += tri[0];
        }
        return (int)*min_element(res.begin(), res.end());
    }
};
