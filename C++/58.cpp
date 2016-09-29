class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string str;
        while(iss>>str);
        return str.length();
    }
};