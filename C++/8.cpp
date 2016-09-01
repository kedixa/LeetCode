class Solution {
public:
    int myAtoi(string str) {
        long long const MAX = 2147483648LL;
        auto it = str.begin();
        bool neg = false;
        long long value = 0;
        /*
            首先去除开始的空格
        */
        while(it != str.end() && *it == ' ') ++it;
        /*
            处理可能存在的符号位
        */
        if(it != str.end() && (*it == '+' || *it == '-'))
        {
            if(*it == '-') neg = true;
            ++it;
        }
        /*
            处理数字，直到第一个不是数字的字符出现
        */
        while(it != str.end())
        {
            if(!isdigit(*it)) break;
            value *= 10;
            value += *it - '0';
            ++it;
            if(value > MAX) break;
        }
        /*
            处理数据溢出的情况
        */
        if(neg)
        {
            if(value > MAX) return -MAX;
            else return -value;
        }
        else
        {
            if(value > MAX - 1) return MAX - 1;
            else return value;
        }
    }
};
