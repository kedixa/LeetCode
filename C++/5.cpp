class Solution {
public:
    string longestPalindrome(string s) {
        // ManacherËã·¨
        int len = s.length();
        string t = string(len * 2 + 3, '\0');
        for(int i = 0; i < len; ++i)
            t[i * 2 + 2] = s[i];
        t[0] = '\1', t[len * 2 + 2] = '\2';
        len = len * 2 + 3;
        vector<int> vec(len, 0);
        int center = 1, far = 1;
        for(int i = 1; i < len - 1; ++i)
        {
            if(far > i) vec[i] = min(vec[2 * center - i], far - i);
            else vec[i] = 1;
            auto &k = vec[i];
            while(t[i + k] == t[i - k]) ++k;
            if(k + i > far) far = k + i, center = i;
        }
        auto it = max_element(vec.begin(), vec.end());
        int c = it - vec.begin(), r = *it;
        auto sub = t.substr(c - r + 1, 2 * r - 1);
        sub.erase(remove(sub.begin(), sub.end(), '\0'), sub.end());
        return sub;
    }
};
