class Solution {
    int largestRectangleArea(vector<int>& heights) {
        /*
         * 先计算出以heights[i]为高的最大矩形的左L[i]右R[i]端点，
         * 再取所有矩形的最大值即可。
         */
        int sz = heights.size();
        vector<int> L(sz), R(sz);
        stack<int> st; // 保存严格升序序列，用于维护左端点
        for(int i = 0; i < sz; ++i)
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) L[i] = 0;
            else L[i] = st.top() + 1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = sz - 1; i >= 0; --i)
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) R[i] = sz - 1;
            else R[i] = st.top() - 1;
            st.push(i);
        }
        int max_area = 0;
        for(int i = 0; i < sz; ++i)
            max_area = max(max_area, heights[i] * (R[i] - L[i] + 1));
        return max_area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        /*
         * 偷个懒，规约到上一个问题来解
        */
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size(), max_rec = 0;
        vector<int> vec(col, 0);
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
                vec[j] = matrix[i][j] == '0' ? 0 : vec[j] + 1;
            max_rec = max(max_rec, largestRectangleArea(vec));
        }
        return max_rec;
    }
};