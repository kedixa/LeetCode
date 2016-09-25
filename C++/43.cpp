class Solution {
    string multi(string& str, int m)
    {
        string s = str;
        auto it = s.rbegin();
        int carry = 0;
        while(it != s.rend())
        {
            carry += (*it - '0') * m;
            *it = carry % 10 + '0';
            carry /= 10;
            ++it;
        }
        if(carry) s = string(1, carry + '0') + s;
        return s;
    }
    string sum(string &s1, string &s2)
    {
        string s;
        auto it1 = s1.rbegin(), it2 = s2.rbegin();
        int carry = 0;
        while(it1 != s1.rend() && it2 != s2.rend())
        {
            carry += (*it1 - '0') + (*it2 - '0');
            s.push_back(carry % 10  + '0');
            carry /= 10;
            ++it1, ++it2;
        }
        while(it1 != s1.rend())
        {
            carry += (*it1 - '0');
            s.push_back(carry % 10 + '0');
            carry /= 10;
            ++it1;
        }
        while(it2 != s2.rend())
        {
            carry += (*it2 - '0');
            s.push_back(carry % 10 + '0');
            carry /= 10;
            ++it2;
        }
        if(carry) s.push_back(carry + '0');
        reverse(s.begin(), s.end());
        return s;
    }
public:
    string multiply(string num1, string num2) {
        /*
            模拟手动乘法即可
        */
        if(num1.length() > num2.length()) swap(num1, num2);
        int len1 = num1.length(), len2 = num2.length();
        string answer = "0";
        reverse(num1.begin(), num1.end());
        for(int i = 0; i < len1; ++i)
        {
            string tmp = multi(num2, num1[i] - '0') + string(i, '0');
            answer = sum(answer, tmp);
        }
        auto it = answer.begin();
        while(it != answer.end() && *it == '0') ++it;
        if(it == answer.end()) return "0";
        else return string(it, answer.end());
    }
};