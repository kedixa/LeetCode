class Solution {
public:
    int maximumGap(vector<int>& nums) {
        using Node=pair<int,int>;
        int sz = nums.size();
        if(sz < 2) return 0;
        // 将sz个元素按照相同的间隔分到sz个桶里
        auto mima = minmax_element(nums.begin(), nums.end());
        int mi = *mima.first, ma = *mima.second;
        int step = (ma - mi + 1) / sz + ((ma - mi + 1) % sz != 0);
        if(mi == ma) return 0;
        vector<Node> v; // 这里只记录最大值和最小值即可
        v.resize(sz, Node(2147483647, -1));
        for(int i = 0; i < sz; ++i) {
            int idx = (nums[i] - mi) / step;
            auto& N = v[idx];
            N.first = min(nums[i], N.first);
            N.second = max(nums[i], N.second);
        }
        // 则取得max gap的两个元素必然在相邻的两个桶之间
        int magap = 0;
        int last_max = mi;
        for(int i = 0; i < sz; ++i) {
            if(v[i].second==-1) continue;
            magap = max(magap, v[i].first - last_max);
            last_max = v[i].second;
        }
        return magap;
    }
};
