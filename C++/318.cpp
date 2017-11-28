class Solution {
public:
    int maxProduct(vector<string>& words) {
        // 用二进制表示字符串中出现的字符
        vector<unsigned> bits(words.size(), 0);
        for(int i = 0; i < words.size(); i++) {
            unsigned b = 0;
            for(auto &c : words[i])
                b |= (1 << (c-'a'));
            bits[i] = b;
        }
        int result = 0;
        for(int i = 0; i < words.size(); i++)
            for(int j = i + 1; j < words.size(); j++)
                if((bits[i]&bits[j])==0)
                    result = max(result, (int)words[i].length() * (int)words[j].length());
        return result;
    }
};
