#define CALCULATE_VALUE_USING_OP(OP) do {\
auto i = st.top();\
st.pop();\
auto j = st.top();\
st.pop();\
st.push(j OP i);\
}while(0);
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const auto &s : tokens)
        {
            if(s.length()==1 && !isdigit(s[0]))
            {
                if(s[0] == '+')
                    CALCULATE_VALUE_USING_OP(+)
                else if(s[0] == '-')
                    CALCULATE_VALUE_USING_OP(-)
                else if(s[0] == '*')
                    CALCULATE_VALUE_USING_OP(*)
                else
                    CALCULATE_VALUE_USING_OP(/)
            }
            else st.push(stoll(s));
        }
        return st.top();
    }
};
