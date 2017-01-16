class Solution {
    using vs = vector<string>;
    vector<vs> result;
    vs tmp;
    vector<vector<int>> next;
    vector<string> vstr;
    bool diff_by_one(const string &a, const string &b)
    {
        int s = 0;
        for(int i = 0; s !=2 && i < a.length(); ++i)
            s += (a[i]!=b[i]);
        return s==1;
    }
    void dfs(int b, int e)
    {
        if(b==e)
        {
            result.push_back(tmp);
            return;
        }
        for(int i = 0; i < next[b].size(); ++i)
        {
            auto &n = next[b][i];
            tmp.push_back(vstr[n]);
            dfs(n, e);
            tmp.pop_back();
        }
        return;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        // 从endWord开始bfs出一棵树，再从beginWord开始dfs出所有结果即可
        // 代码效率较低，有待提高
        result.clear();
        next.clear();
        int b, e;
        vstr.assign(wordList.begin(), wordList.end());
        if(wordList.find(beginWord)!=wordList.end()) b = find(vstr.begin(), vstr.end(), beginWord) - vstr.begin();
        else vstr.push_back(beginWord), b = vstr.size() - 1;
        if(wordList.find(endWord)!=wordList.end()) e = find(vstr.begin(), vstr.end(), endWord) - vstr.begin();
        else vstr.push_back(endWord), e = vstr.size() - 1;
        // bfs from endWord to beginWord
        vector<int> depth(vstr.size(), 99999999);
        next.resize(vstr.size());
        queue<int> que;
        que.push(e);
        depth[e]=0;
        while(!que.empty() && depth[b]==99999999)
        {
            int sz = que.size();
            while(sz--)
            {
                int p = que.front();
                que.pop();
                for(int i = 0; i < vstr.size(); ++i)
                {
                    if(depth[i] > depth[p] && diff_by_one(vstr[i], vstr[p]))
                    {
                        next[i].push_back(p);
                        if(depth[i]==99999999) que.push(i);
                        depth[i] = depth[p]+1;
                    }
                }
            }
        }
        // dfs from beginWord to endWord
        tmp.clear();
        tmp.push_back(vstr[b]);
        dfs(b, e);
        return result;
    }
};
