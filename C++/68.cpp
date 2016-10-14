class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        /*
            贪心地将连续多个words放到一个字符串中，注意预留word之间的空格。
        */
        vector<string> ans;
        int sz = words.size();
        int s = 0, t = 0, cur = 0;
        while(t < sz)
        {
            if(cur + words[t].length() + (t - s) > maxWidth)
            {
                int space, more;
                if(t - s > 1) space = (maxWidth - cur)/(t - s - 1), more = (maxWidth - cur)%(t - s - 1);
                else space = maxWidth - cur, more = 0;
                string str = words[s];
                for(++s; s < t; ++s)
                {
                    str += string(space, ' ');
                    if(more) str += ' ', --more;
                    str += words[s];
                }
                str += string(maxWidth - str.length(), ' ');
                ans.push_back(str);
                if(t != sz) cur = words[t].size();
            }
            else
            {
                cur += words[t].length();
            }
            ++t;
        }
        if(s < sz)
        {
            string str = words[s];
            for(++s; s < sz; ++s)
                str += ' ' + words[s];
            str += string(maxWidth - str.length(), ' ');
            ans.push_back(str);
        }
        return ans;
    }
};