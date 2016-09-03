class Solution {
    int common_prefix(string &a, string &b, int _max)
    {
        int s = 0, sz = min(a.length(), b.length());
        sz = min(sz, _max);
        while(s < sz && a[s] == b[s]) ++s;
        return s;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
            ���������ַ������㹫��ǰ׺����ȡ��Сֵ����
        */
        int sz = strs.size();
        if(sz == 0) return string();
        int ans = strs[0].length();
        for(int i = 1; i < sz; ++i)
            ans = min(ans, common_prefix(strs[i - 1], strs[i], ans));
        return strs[0].substr(0, ans);
    }
};
