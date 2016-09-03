class Solution {
    string digit_to_roman(int digit, char a, char b, char c)
    {
        /*
            �ú������ڴ���һ����λ��������������ɣ�
            ����a��b��c�ֱ������ʮ�������һ
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
            ǧλ����λ��ʮλ�͸�λ�ֱ�����
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
