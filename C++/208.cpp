class Trie {
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
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(const auto &c : word) {
            if(p->child[c-'a']==nullptr)
                p->child[c-'a'] = new TrieNode();
            p = p->child[c-'a'];
        }
        p -> hasWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for(const auto &c : word) {
            p = p->child[c-'a'];
            if(p == nullptr) return false;
        }
        return p->hasWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(const auto &c : prefix) {
            p = p->child[c-'a'];
            if(p == nullptr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
