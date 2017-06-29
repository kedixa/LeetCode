class Solution {
    string uint2str(unsigned p) {
        // 从hash映射回string
        static const char ch[4]= {'A', 'C', 'G', 'T'};
        string str(10, ' ');
        for(int i = 9; i >= 0; --i) {
            str[i] = ch[p%4];
            p /= 4;
        }
        return str;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 10) return {};
        // 长度为10的串可表示成20个bit的整数
        unsigned hash = 0;
        unsigned mask = (1<<20) - 1;
        unsigned h[128];
        h['A'] = 0x00, h['C'] = 0x01, h['G'] = 0x02, h['T'] = 0x03;
        for(int i = 0; i < 9; ++i) hash = (hash << 2) | h[s[i]];
        // 将每个串的hash放到unordered_map里计数
        unordered_map<unsigned, int> um;
        for(int i = 9; i < s.length(); ++i) {
            hash = (hash << 2) | h[s[i]];
            hash &= mask;
            ++um[hash];
        }
        // 取计数大于1的即可
        vector<string> vs;
        for(const auto &p : um)
            if(p.second > 1) vs.push_back(uint2str(p.first));
        return vs;
    }
};
