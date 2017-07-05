class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int s = 0, t = 1;
        int sz = nums.size();
        vector<string> result;
        string str;
        while(s != sz) {
            while(t != sz && nums[t] == nums[t-1] + 1) ++t;
            str = to_string(nums[s]);
            if(s + 1 != t) str += "->" + to_string(nums[t-1]);
            result.push_back(str);
            s = t;
            ++t;
        }
        return result;
    }
};
