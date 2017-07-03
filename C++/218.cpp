class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        const auto &bs = buildings;
        int sz = bs.size();
        vector<pair<int,int>> result;
        multiset<int, greater<int>> height; // 扫描范围的所有高度
        multimap<int, int> mp; // 记录每个长方形何时退出扫描范围
        height.insert(0);      // 插入一个地平线，作为最小高度
        for(int i = 0; i < sz;) {
            // 将下一个x坐标插入扫描范围
            int cur_x = bs[i][0];
            int last_max_height = *height.begin();
            while(i < sz && cur_x == bs[i][0]) {
                height.insert(bs[i][2]);
                mp.insert({bs[i][1], bs[i][2]});
                ++i;
            }
            // 如果插入的高度高于之前的高度，则该点为所求
            if(*height.begin() > last_max_height) {
                result.push_back({cur_x, *height.begin()});
            }
            // 将下一个x坐标前的长方形的结束位置都移出扫描范围
            while(!mp.empty()) {
                auto it = mp.begin();
                if(i < sz && it->first >= bs[i][0]) break;
                int that_x = it->first, that_height = *height.begin();
                while(!mp.empty()) {
                    it = mp.begin();
                    if(it->first != that_x) break;
                    height.erase(height.find(it->second));
                    mp.erase(it);
                }
                // 若移出后，高度降低，则该点为所求
                if(*height.begin() < that_height) {
                    result.push_back({that_x, *height.begin()});
                }
            }
        }
        return result;
    }
};
