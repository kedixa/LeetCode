class Solution {
public:
    static regex e;
    bool isNumber(string s) {
        /*
            暂时偷个懒
        */
        return regex_match(s, e);
    }
};
regex Solution::e = regex("\\s*(([-\\+]?[0-9]+(\\.[0-9]*)?(e[-\\+]?[0-9]+)?)|([-\\+]?\\.[0-9]+(e[-\\+]?[0-9]+)?))\\s*");