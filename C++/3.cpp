class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
            一个时间复杂度O(n^2)的方法是枚举子串的开始位置，从这个位置向后查看可以到达的最远位置；
            或者枚举子串的结束位置，从这个位置向前查看可以到达的最远位置。
            通过维护一些信息，可以得到O(n)的解法。
        */

        // last_appeare 用来维护字符s[i]上一次出现的位置，如果该子串以s[i]结尾，
        // 则最早的位置应该在last_appeare[s[i]]之后（不然至少有一个字符重复）
        vector<int> last_appeare(128, -1);

        /*
            min_bound 根据之前的信息来维护以s[i]结尾的子串的开始位置的一个下界
            以“aab”为例（下标从0开始），当枚举到s[1]时，发现字母‘a’上一次出现的位置是0，
            为了不重复出现字母‘a’，则子串至少从位置1开始，而且此后的所有的开始位置都不可能更早；
            当枚举到s[2]时，last_appeare表示字母‘b’还没出现过，但min_bound表示，
            如果该子串从位置0开始，会有另一个字母发生重复，所以需要从位置1开始。
        */
        int len = s.length(), max_length = 0, min_bound = -1;
        for(int i = 0; i < len; ++i)
        {
            min_bound = max(min_bound, last_appeare[s[i]]);
            max_length = max(max_length, i - min_bound);
            last_appeare[s[i]] = i;
        }
        return max_length;
    }
};
