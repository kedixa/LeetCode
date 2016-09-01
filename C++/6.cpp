class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if(len < 2 || numRows < 2) return s;

        /*
            首先建立用来保存每行字符串的vector<string>
        */
        vector<string> vec(numRows);
        for(auto &str : vec)
            str.reserve(len / (numRows - 1) + 1);

        /*
            除了第一个字符特殊处理外，其他的都是从第二行到最后一行，
            再从倒数第二行到第一行依次放置
        */
        auto it = s.begin();
        vec[0].push_back(*it++);
        while(it != s.end())
        {
            for(int i = 1; i < numRows && it != s.end(); ++i)
                vec[i].push_back(*it++);
            for(int i = numRows - 2; i >= 0 && it != s.end(); --i)
                vec[i].push_back(*it++);
        }
        return accumulate(vec.begin(), vec.end(), string());
    }
};
