class Solution {
    bool check(multiset<string> &ms, vector<string>& vs)
    {
        auto it1 = ms.begin();
        auto it2 = vs.begin();
        while(it1 != ms.end())
        {
            if(*it1 != *it2) return false;
            ++it1, ++it2;
        }
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        /*
        遍历所有的子串，判断是否可以由words的一个排列构成。
        */
        int len_s = s.length();
        int size_w = words.size();
        assert(size_w > 0);
        int len_w = words[0].length();
        sort(words.begin(), words.end());
        vector<int> result;
        if(len_w == 0)
        {
            // 特殊情况
            for(int i = 0; i < len_s + 1; i++)
                result.push_back(i);
            return result;
        }

        for(int i = 0; i < len_w; ++i)
        {
            if(i + size_w * len_w > len_s) break;
            multiset<string> ms;
            for(int j = i; j < i + (size_w - 1) * len_w; j += len_w)
                ms.insert(s.substr(j, len_w));
            for(int j = i + (size_w - 1) * len_w; j < len_s; j += len_w)
            {
                ms.insert(s.substr(j, len_w));
                if(check(ms, words)) result.push_back(j - (size_w - 1) * len_w);
                auto it = ms.find(s.substr(j - (size_w - 1) * len_w, len_w));
                ms.erase(it);
            }
        }
        return result;
    }
};