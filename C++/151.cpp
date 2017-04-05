class Solution {
public:
    void reverseWords(string &s) {
        // 两个单词之间可能有多个空格，但翻转后只能有一个，
        // 原地翻转可能会比较麻烦，所以用了最朴素的方法
        istringstream iss(s);
        string tmp, word;
        tmp.reserve(s.length());
        while(iss >> word)
        {
            reverse(word.begin(), word.end());
            tmp += word;
            tmp += " ";
        }
        while(tmp.back() == ' ') tmp.pop_back();
        s = tmp;
        reverse(s.begin(), s.end());
    }
};
