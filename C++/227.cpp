class Solution {
public:
    int calculate(string s) {
        // 用栈模拟
        const char *ch = s.c_str();
        stack<long long> number;
        stack<char> op;
        while(*ch != '\0') {
            while(*ch == ' ') ++ch;
            if(*ch == '\0') break;
            if(*ch == '+' || *ch == '-') {
                // 如果遇到+或-，则处理之前可能存在的+ 或-
                if(!op.empty()) {
                    char c = op.top();
                    op.pop();
                    long long n2 = number.top();
                    number.pop();
                    long long n1 = number.top();
                    number.pop();
                    if(c == '+') n1 += n2;
                    else if (c == '-') n1 -= n2;
                    number.push(n1);
                }
                op.push(*ch);
                ++ch;
            }
            else if(*ch == '*' || *ch == '/') {
                // 如果遇到*或/，则直接放入
                op.push(*ch);
                ++ch;
            }
            else {
                // 遇到数字则应当处理之前可能存在的*或/
                long long n2 = *ch - '0';
                ++ch;
                while(*ch != '\0' && isdigit(*ch)) {
                    n2 *= 10;
                    n2 += *ch - '0';
                    ++ch;
                }
                if(!op.empty() && (op.top() == '*' || op.top() == '/')) {
                    char c = op.top();
                    op.pop();
                    long long n1 = number.top();
                    number.pop();
                    if(c == '*') n2 = n1 * n2;
                    else if(c == '/') n2 = n1 / n2;
                }
                number.push(n2);
            }
        }
        // 最后可能剩下一个+或-
        if(!op.empty()) {
            char c = op.top();
            op.pop();
            long long n2 = number.top();
            number.pop();
            long long n1 = number.top();
            number.pop();
            if(c == '+') n1 += n2;
            else if (c == '-') n1 -= n2;
            number.push(n1);
        }
        return number.top();
    }
};
