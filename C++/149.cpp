/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    class pairhash {
        public:
        std::size_t operator()(const pair<int, int> &p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
    int gcd(int x, int y)
    {
        if(x % y == 0) return y;
        return gcd(y, x%y);
    }
    pair<int, int> get_direction(const Point &p, const Point &q)
    {
        auto r = make_pair(p.x - q.x, p.y - q.y);
        if(r.first < 0) r.first = -r.first, r.second = -r.second;
        if(r.first == 0) r.second = 1;
        else if(r.second == 0) r.first = 1;
        else {
            int g = gcd(r.first, r.second);
            r.first /= g, r.second /= g;
        }
        return r;
    }
public:
    int maxPoints(vector<Point>& points) {
        // 枚举每个点，遍历所有的点，统计在每个方向上点的个数
        int max_point = 0;
        unordered_set<pair<int, int>, pairhash> us;
        for(const auto &p : points) // 枚举
        {
            // 如果同样的点已经计算过，就忽略
            if(us.find(make_pair(p.x, p.y)) == us.end())
                us.insert(make_pair(p.x, p.y));
            else continue;

            int m = 0; // number of same points as p
            // hash表保存每个方向上点的个数
            unordered_map<pair<int, int>, int, pairhash> ump;
            ump.reserve(points.size());
            for(const auto &q : points) // 遍历所有的点
            {
                if(p.x == q.x && p.y == q.y) ++m;
                else
                {
                    // 方向定义为(-180, 180]度角内的(x, y)，其中gcd(x, y)==1
                    // 因此每个角度有且仅有一种表示
                    auto dire = get_direction(p, q);
                    auto it = ump.find(dire);
                    if(it == ump.end()) ump.insert({dire, 1});
                    else ++(it->second);
                }
            }
            int a = 0;
            for(const auto &x : ump)
                if(a < x.second) a = x.second;
            max_point = max(max_point, a + m);
        }
        return max_point;
    }
};
