class Solution {
public:
    string minWindow(string s, string t) {
        // 用数组记下t中每个元素出现的次数，遍历s
        vector<int> vec(256, 0);
        for(auto &c : t) vec[c]++;
        int num = 256 - count(vec.begin(), vec.end(), 0);
        int start = -1;
        string str;
        for(int i = 0; i < s.length(); ++i)
        {
            auto &c = s[i];
            vec[c]--; // 从数组中减去1
            if(vec[c] == 0) num--; // num表示数组中大于0的元素个数
            if(num == 0)
            { // 若num为0则表示t中所有字符已经包含在s(start, i]之间了
              // 处理这段字符，更新结果，并继续寻找
                while(start++ < i)
                {
                    auto &x = vec[s[start]];
                    x++;
                    if(x == 1)
                    {
                        num++;
                        break;
                    }
                }
                if(str.length() == 0 || str.length() > i - start + 1)
                    str = s.substr(start, i - start + 1);
            }
        }
        return str;
    }
};