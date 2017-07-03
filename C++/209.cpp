class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sz = nums.size(), mlen = sz + 1;
        int sum = 0;
        int p1 = 0, p2 = 0;
        while(p2 != sz) {
            while(sum < s && p1 != sz) sum += nums[p1++];
            if(sum >= s) mlen = min(mlen, p1 - p2);
            sum -= nums[p2++];
        }
        return (mlen>sz)?0:mlen;
    }
};
