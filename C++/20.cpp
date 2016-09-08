class Solution {
public:
    bool isValid(string s) {
        /*
            遇到前括号放到栈中,遇到后括号查看是否与栈顶的括号匹配
        */
        stack<char> st;
        for(auto &c : s)
        {
            switch (c)
            {
            case '(': case '[': case '{':
                st.push(c);
                break;
            case ')':
                if(st.empty() || st.top() != '(') return false;
                st.pop();
                break;
            case ']': case '}':
                if(st.empty() || st.top() != c - 2) return false;
                st.pop();
                break;
            default:
                return false;
            }
        }
        return st.empty();
    }
};