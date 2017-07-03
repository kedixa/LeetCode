class WordDictionary {
    class TrieNode {
        public:
        TrieNode* child[26];
        bool hasWord;
        TrieNode() {
            fill(child, child+26, nullptr);
            hasWord = false;
        }
        ~TrieNode() {
            for(auto p : child)
                if(p) delete p;
        }
    };
    TrieNode *root;
    bool search(TrieNode *p, const char *ch) {
        // 在trie中递归查找
        if(*ch == '\0') // 遇到单词结尾
            return p!=nullptr && p->hasWord == true;
        else if(p == nullptr) // 子树为空
            return false;
        else if(*ch != '.') {
            return search(p->child[*ch-'a'], ch + 1);
        }
        else if(*ch == '.') {
            for(int i = 0; i < 26; ++i)
                if(p->child[i] != nullptr)
                    if(search(p->child[i], ch + 1))
                        return true;
        }
        return false;
    }
public:
    // 建一棵trie，递归查找单词是否存在即可
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
		TrieNode *p = root;
        for(const auto &c : word) {
            if(p->child[c-'a']==nullptr)
                p->child[c-'a'] = new TrieNode();
            p = p->child[c-'a'];
        }
        p -> hasWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        const char *ch = word.c_str();
        return search(root, ch);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
