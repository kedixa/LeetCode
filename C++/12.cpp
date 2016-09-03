class Solution {
    string digit_to_roman(int digit, char a, char b, char c)
    {
        /*
            该函数用于处理一个数位，分四种情况即可，
            其中a，b，c分别代表整十、整五和一
        */
        string ans;
        if(digit == 9) ans += string(1, c) + string(1, a);
        else if(digit >= 5) ans += string(1, b) + string(digit - 5, c);
        else if(digit == 4) ans += string(1, c) + string(1, b);
        else ans += string(digit, c);
        return ans;
    }
public:
    string intToRoman(int num) {
        string ans;

        /*
            千位、百位、十位和个位分别处理即可
        */

        int tmp = num / 1000;
        num %= 1000;
        ans += string(tmp, 'M');

        tmp = num / 100;
        num %= 100;
        ans += digit_to_roman(tmp, 'M', 'D', 'C');

        tmp = num / 10;
        num %= 10;
        ans += digit_to_roman(tmp, 'C', 'L', 'X');

        ans +=digit_to_roman(num, 'X', 'V', 'I');
        return ans;
    }
};
