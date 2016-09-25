class Solution {
public:
    int trap(vector<int>& height) {
        /*
            枚举每个位置i，从这个位置向前查找最近的比它大的数，
            若找到了这个位置a，则位于区间(a, i)中的位置的（放满水的）高度至少可为height[i]；
            若没有这个位置，则在区间(0, i)中存在一个最远的(设为a)最大的数，
            这样位于区间(a, i)中的位置的高度至少可为height[a]。
        */
        vector<int> max_height(height);
        stack<int> st; // 使用栈维护下降序列
        for(int i = 0; i < height.size(); ++i)
        {
            /*
            寻找位置a，
            */
            int pre = -1;
            while(!st.empty() && height[st.top()] <= height[i])
            {
                pre = st.top();
                st.pop();
            }
            /*
            分两种情况讨论，此处可使用数据结构对区间进行快速修改，比如线段树。
            */
            if(st.empty() && pre >= 0)
                fill(max_height.begin() + pre + 1, max_height.begin() + i, height[pre]);
            else if(!st.empty()) fill(max_height.begin() + st.top() + 1, max_height.begin() + i, height[i]);
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < height.size(); ++i)
            ans += (max_height[i] - height[i]);
        return ans;
    }
};