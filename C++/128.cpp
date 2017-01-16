class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ump 保存一段连续的数的长度
        // 比如其中已经有[1, 2, 3] 和 [5, 6]，ump[1]=ump[3]=3，ump[5]=ump[6]=2
        // 插入4之后，ump[1]=ump[4]=ump[6]=6，其余位置不需要修改，因为不会再被访问
        unordered_map<int, int> ump;
        int result = 0;
        for(auto &x : nums)
        {
            if(ump[x]) continue;
            int m = ump[x-ump[x-1]]+ump[x+ump[x+1]]+1;
            ump[x] = ump[x-ump[x-1]] = ump[x+ump[x+1]] = m;
            result = max(result, m);
        }
        return result;
    }
};
