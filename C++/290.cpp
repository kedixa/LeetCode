class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        string s;
        map<char, string> m;
        for(auto c : pattern) {
            auto it = m.find(c);
            iss >> s;
            if(!iss) return false;
            if(it == m.end()) m[c] = s;
            else if(it->second != s) return false;
        }
        set<string> se;
        for(auto p : m) {
            if(se.find(p.second) != se.end()) return false;
            se.insert(p.second);
        }
        return iss.eof();
    }
};
