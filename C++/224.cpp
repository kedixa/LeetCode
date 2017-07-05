class Solution {
public:
    int calculate(string s) {
        // 用栈模拟计算即可
        stack<long long> number;
        stack<char> op;
        const char *ch = s.c_str();
        while(*ch != '\0') {
            while(*ch == ' ') ++ch;
            if(*ch == '\0') break;
            if(*ch == '(' || *ch == '+' || *ch == '-') {
                // 这些符号直接插入，暂时不需要计算
                op.push(*ch);
                ++ch;
            }
            else if(*ch == ')') {
                // 遇到后括号则应当消除前括号并处理可能存在的计算
                op.pop(); // 必定为'('
                if(!op.empty() && (op.top() == '+' || op.top() == '-')) {
                    long long n2 = number.top();
                    number.pop();
                    long long n1 = number.top();
                    number.pop();
                    if(op.top() == '+') n1 += n2;
                    else n1 -= n2;
                    op.pop();
                    number.push(n1);
                }
                ++ch;
            }
            else {
                // 遇到数字则读取并处理可能存在的计算
                long long n = *ch - '0';
                ++ch;
                while(*ch != '\0' && isdigit(*ch)) {
                    n *= 10;
                    n += (*ch - '0');
                    ++ch;
                }
                number.push(n);
                if(!op.empty() && (op.top() == '+' || op.top() == '-')) {
                    long long n2 = number.top();
                    number.pop();
                    long long n1 = number.top();
                    number.pop();
                    if(op.top() == '+') n1 += n2;
                    else n1 -= n2;
                    op.pop();
                    number.push(n1);
                }
            }
        }
        // 最后number栈中的数据即为结果
        return number.top();
    }
};
