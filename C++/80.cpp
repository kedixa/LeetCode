class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 数相邻的数的个数，若大于2则去掉多余的部分
        auto it = nums.begin();
        while(it != nums.end())
        {
            auto it2 = it + 1;
            while(it2 != nums.end() && *it2 == *it) ++it2;
            int dist = distance(it, it2);
            if(dist > 2)
            {
                it = it + 2;
                while(it != it2) *(it++) = 0x7fffffff; // 若数组中有该数，则出错
            }
            it = it2;
        }
        it = remove(nums.begin(), nums.end(), 0x7fffffff);
        return distance(nums.begin(), it);
    }
};