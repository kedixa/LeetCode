class Solution {
    using vs = vector<string>;
    bool legal(const string &s)
    {// 判断该数是否合法
        int len = s.length();
        if(len > 3) return false;
        if(len == 1) return true;
        if(len == 2) return s[0] != '0';
        return s[0] != '0' && stoi(s) < 256;
    }
    void dfs(int cur, int k, string &s, vs &tmp, vs &vec)
    {
        if(k == s.length())
        { // 终止条件
            if(cur != 3) return;
            string str = tmp[0];
            for(int i = 1; i < 4; ++i) str += "." + tmp[i];
            vec.push_back(str);
            return;
        }
        // 若cur位置上有数且cur不为3，则可以添加一个点
        if(tmp[cur].length() != 0 && cur != 3)
            dfs(cur + 1, k, s, tmp, vec);
        // 在cur处增加一个字符，若合法则递归
        tmp[cur].push_back(s[k]);
        if(legal(tmp[cur])) dfs(cur, k+1, s, tmp, vec);
        tmp[cur].pop_back();
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        // 枚举四个位置上的可能值即可
        vector<string> vec;
        vector<string> tmp{"", "", "", ""};
        dfs(0, 0, s, tmp, vec);
        return vec;
    }
};