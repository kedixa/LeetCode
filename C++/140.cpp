class Solution {
    struct Node {
        Node *child[128];
        bool is_word;
        string s;
        Node() {
            is_word = false;
            fill(child, child + 128, nullptr);
        }
        ~Node() {
            for(auto &p : child) delete p;
        }
    };
    Node *tree;
    void add(const string &s) {
        Node **p = &tree;
        for(auto &c : s) {
            auto t = *p;
            if(t -> child[c] == nullptr)
                t -> child[c] = new Node();
            p = &(t -> child[c]);
        }
        (*p) -> is_word = true;
        (*p) -> s = s;
    }
    void build_tree(vector<string> &words) {
        for(auto &s : words)
            add(s);
    }
    bool isWordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        int max_len = 0;
        for(auto &x : wordDict) max_len = max(max_len, (int)x.length());
        vector<int> dp(s.length()+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= s.length(); ++i)
        {
            int j = i - 1;
            for(j; j >=0 && i-j <= max_len; --j)
                if(dp[j] == 1 && us.find(s.substr(j, i-j)) != us.end())
                {
                    dp[i] = 1;
                    break;
                }
        }
        return dp.back();
    }
    
    vector<string> result;
    vector<string> tmp;
    int len;
    
    void dfs(Node *p, const char *s, const char *t) {
        if(s == t) {
            if(p->is_word) tmp.push_back(p->s);
            else return;
            string str;
            str.reserve(len + tmp.size());
            for(auto &x : tmp) {
                str += x;
                str.push_back(' ');
            }
            str.pop_back();
            result.push_back(std::move(str));
            tmp.pop_back();
            return;
        }
        if(p->is_word) {
            tmp.push_back(p->s);
            dfs(tree, s, t);
            tmp.pop_back();
        }
        if(p->child[*s]) {
            dfs(p->child[*s], s+1, t);
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 效率有待提高
        // 先判断是否有解，再使用递归的方法依次添加一个单词，直到字符串结尾
        if(!isWordBreak(s, wordDict)) return result;
        tree = new Node();
        build_tree(wordDict);
        result.clear();
        tmp.clear();
        len = s.length();
        dfs(tree, s.c_str(), s.c_str() + len);
        delete tree;
        return result;
    }
};
