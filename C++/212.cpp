class Solution {
    using vvc = vector<vector<char>>;
    class TrieNode {
        public:
        TrieNode *child[26];
        bool flag; // 当前结点是否是一个单词的结束
        string word; // 当前结点表示的单词
        TrieNode() {
            fill(child, child+26, nullptr);
            flag = false;
        }
        ~TrieNode() {
            for(int i = 0; i < 26; ++i)
                if(child[i] != nullptr) delete child[i];
        }
    };
    TrieNode *root;
    int row, col; // board的大小
    vector<string> cur_words; // 已经搜到的串
    void insert(const string& word) {
        // 向树中插入单词
        TrieNode *p = root;
        const char *ch = word.c_str();
        while(*ch != '\0') {
            if(p->child[*ch - 'a'] == nullptr)
                p->child[*ch - 'a'] = new TrieNode();
            p = p->child[*ch - 'a'];
            ++ch;
        }
        p -> flag = true;
        p -> word = word;
    }
    void dfs(vvc& board, int r, int c, TrieNode* p) {
        const static int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        if(p == nullptr) return; // 子树为空则返回
        if(p->flag) {
            // 当前查找到一个单词，加入已查找到的记录中
            cur_words.push_back(p->word);
            p->flag = false;
        }
        // 不符合条件的返回
        if(r < 0 || r >= row || c < 0 || c >= col || board[r][c] == '.') return;
        // 将当前点标识为'.'表示已访问
        char ch = board[r][c];
        board[r][c] = '.';
        if(p->child[ch-'a']) {
            for(int i = 0; i < 4; i++) {
                dfs(board, r+dir[i][0], c+dir[i][1], p->child[ch-'a']);
            }
        }
        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 将words构建一棵trie，然后借助trie，枚举单词起始点并递归搜索单词
        root = new TrieNode();
        cur_words.clear();
        for(const auto &s : words) insert(s);
        cur_words.clear();
        row = board.size();
        if(row == 0) {
            delete root;
            return cur_words;
        }
        col = board[0].size();
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                dfs(board, i, j, root);
            }
        }
        delete root;
        return cur_words;
    }
};
