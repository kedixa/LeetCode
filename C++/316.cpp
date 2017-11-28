class Solution {
public:
    string removeDuplicateLetters(string s) {
        // next[i]表示字符s[i]下次一出现的位置，不存在则为-1
        // 找到第一个使得next[i] 为-1的位置，在s[0..i]中找一个最小的字符加入到结果字符串中
        // 删除经过此过程后不可能再被选取的字符，重复以上过程，直到没有字符可以选取
        vector<int> vec(26, -1); // 记录每个字母出现的位置
        int len = s.length();
        if(len < 2) return s;
        vector<int> next(len, -1);
        for(int i = len - 1; i >= 0; i--) {
            next[i] = vec[s[i] - 'a'];
            vec[s[i] - 'a'] = i;
        }
        string str; // 保存结果
        do {
            int pos = find(next.begin(), next.end(), -1) - next.begin();
            if(pos == len) break;
            int midx = 0;
            while(next[midx] == -2) ++midx;
            for(int i = 0; i <= pos; i++) {
                if(next[i] != -2 && s[i] < s[midx])
                    midx = i;
            }
            str += s[midx];
            for(int i = 0; i < midx; i++)
                next[i] = -2;
            int tmp;
            while(midx != -1) {
                tmp = next[midx];
                next[midx] = -2;
                midx = tmp;
            }
        } while(true);
        return str;
    }
};
