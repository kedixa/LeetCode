class Solution {
public:
    bool isPalindrome(int x) {
        /*
            讲道理这个题可能不存在“without extra space”的解法，
            这种说法只是为了禁止定义数组。
            定义另一个变量y，每次移动x最后一个数字到y的后面，
            如果x和y出现相等的情况，则x是一个回文数。
            例如：x = 1001, y = 0
                => x = 100, y = 1
                => x = 10, y = 10 !!Bingo
        */
        if(x == 0) return true;
        if(x < 0 || x % 10 == 0) return false;
        int y = 0;
        while(x > y)
        {
            int tmp = x%10;
            x /= 10;
            /*
            此处是为了处理回文长度为奇数的情况
            */
            if(x == y) return true;
            y *= 10;
            y += tmp;
            if(x == y) return true;
        }
        return false;
    }
};
