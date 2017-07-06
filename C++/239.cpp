class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 对[i-k+1, i]的数据维护一个单调下降的双端队列，
        // 每次位于队列前面的数据为所求
        int sz = nums.size();
        vector<int> vec;
        if(sz == 0 || sz < k) return vec;
        deque<int> dq;
        for(int i = 0; i < k - 1; ++i) {
            while(!dq.empty()) {
                int q = dq.back();
                if(nums[q] <= nums[i])
                    dq.pop_back();
                else break;
            }
            dq.push_back(i);
        }
        for(int i = k - 1; i < sz; ++i) {
            if(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            while(!dq.empty()) {
                int q = dq.back();
                if(nums[q] <= nums[i])
                    dq.pop_back();
                else break;
            }
            dq.push_back(i);
            vec.push_back(nums[dq.front()]);
        }
        return vec;
    }
};
