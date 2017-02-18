class Solution {
public:
    int candy(vector<int>& ratings) {
        // 还有更好的方法
        if(ratings.size() == 0) return 0;
        vector<int> r(ratings.size()+2);
        copy(ratings.begin(), ratings.end(), r.begin() + 1);
        r[0] = r.back() = numeric_limits<int>::max();
        vector<pair<int,int>> v;
        v.reserve(ratings.size());
        for(int i = 0; i < ratings.size(); ++i)
            v.push_back(make_pair(ratings[i], i + 1));
        sort(v.begin(), v.end());
        for(auto &x : v)
        {
            int &y = x.second;
            ratings[y-1] = 1;
            if(r[y-1] < r[y] && ratings[y-1] <= ratings[y-2]) ratings[y-1] = ratings[y-2] + 1;
            if(r[y+1] < r[y] && ratings[y-1] <= ratings[y]) ratings[y-1] = ratings[y] + 1;
        }
        return accumulate(ratings.begin(), ratings.end(), 0);
    }
};
