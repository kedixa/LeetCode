class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
            以（将字符串中的字母排序后的结果）作为字符串的特征值，
            特征相同的字符串放到同一个vector中。
        */
        vector<vector<string>> result;
        unordered_map<string, int> umsi;
        for(int i = 0; i < strs.size(); ++i)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(umsi.find(tmp) == umsi.end())
            {
                umsi[tmp] = result.size();
                result.push_back(vector<string>());
            }
            result[umsi[tmp]].push_back(strs[i]);
        }
        return result;
    }
};