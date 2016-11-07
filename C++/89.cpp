class Solution {
public:
    vector<int> grayCode(int n) {
        /*
         * 可以打表，直接算也没事。
         * 首先查看一下前几组数据，就能发现规律了。
         * 假设第i组的结果为v(i)，那么第i+1组的结果就是(v(i),reverse(v(i))+ 2^i)
        */
        vector<int> vec = {0};
        vec.reserve(1<<n); // 预分配空间，防止迭代器失效
        int adds = 1;
        while(n--)
        {
            auto it = vec.rbegin();
            while(it != vec.rend()) vec.push_back(*it++ + adds);
            adds *= 2;
        }
        return vec;
    }
};