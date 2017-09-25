class Solution {
    vector<string> result; // 保存结果
    int t;             // target
    long long eval(const string &s) {
        // 对一个表达式求值
        const char *p = s.c_str();
        long long num[4], n;
        char op[4];
        int sz_num = 0, sz_op = 0;
        while(*p != '\0') {
            n = 0;
            if(isdigit(*p)) {
                if(*p == '0' && *(p+1) == ' ') return !t;
                while(isdigit(*p)) {
                    n = n * 10 + (*p - '0');
                    ++p;
                    if(*p == ' ') ++p;
                }
                if(sz_op && op[sz_op - 1] == '*')
                    num[sz_num - 1] = num[sz_num - 1] * n, --sz_op;
                else num[sz_num++] = n;
            }
            else {
                if(*p == '+' || *p == '-') {
                    if(sz_op && op[sz_op - 1] == '+')
                        num[sz_num - 2] = num[sz_num - 2] + num[sz_num - 1], --sz_num, --sz_op;
                    if(sz_op && op[sz_op - 1] == '-')
                        num[sz_num - 2] = num[sz_num - 2] - num[sz_num - 1], --sz_num, --sz_op;
                }
                op[sz_op++] = *p;
                ++p;
            }
        }
        if(sz_op)
        {
            if(op[sz_op - 1] == '+') num[sz_num - 2] = num[sz_num - 2] + num[sz_num - 1];
            else if(op[sz_op - 1] == '-') num[sz_num - 2] = num[sz_num - 2] - num[sz_num - 1];
        }
        return num[0];
    }
    void dfs(string &s, int p) {
        // 给每个可能的位置添加运算符
        if(p >= s.length()) {
            if(eval(s) == t)
                result.push_back(s);
            return;
        }
        for(char c : {' ', '+', '-', '*'}) {
            s[p] = c;
            dfs(s, p + 2);
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        if(num.length() == 0) return {};
        result.clear();
        t = target;
        string s;
        // 添加空间，便于放置运算符
        for(auto &c : num)
            s.push_back(c), s.push_back(' ');
        s.pop_back();
        dfs(s, 1);
        // 删除多余的空格
        for(auto &r : result)
            r.erase(remove(r.begin(), r.end(), ' '), r.end());
        return result;
    }
};
