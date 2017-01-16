class Solution {
    bool diff_by_one(const string &a, const string &b)
    {
        int s = 0;
        for(int i = 0; s !=2 && i < a.length(); ++i)
            s += (a[i]!=b[i]);
        return s==1;
    }
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        // 效率不佳，有待提高
        vector<string> vstr(wordList.begin(), wordList.end());
        vstr.push_back(beginWord), vstr.push_back(endWord);
        int b = vstr.size()-2, e = vstr.size()-1;
        queue<int> que;
        vector<int> depth(vstr.size(), 99999999);
        que.push(b);
        depth[b] = 0;
        while(!que.empty() && depth[e] == 99999999)
        {
            int q = que.front();
            que.pop();
            for(int i = 0; i < vstr.size(); ++i)
            {
                if(depth[i] > depth[q] + 1 && diff_by_one(vstr[i], vstr[q]))
                {
                    que.push(i);
                    depth[i] = depth[q] + 1;
                }
            }
        }
        if(depth[e]==99999999) return 0;
        return depth[e] + 1;
    }
};
