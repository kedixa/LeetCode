class Solution {
    using si = string::iterator;
    bool equal(si first1, si last1, si first2)
    {
        while(first1 != last1)
        {
            if(*first1 != *first2) return false;
            ++first1, ++first2;
        }
        return true;
    }
public:
    int strStr(string haystack, string needle) {
        int lh = haystack.length(), ln = needle.length();
        for(int i = 0; i <= lh - ln; ++i)
        {
            if(equal(haystack.begin() + i, haystack.begin() + i + ln, needle.begin()))
                return i;
        }
        return -1;
    }
};