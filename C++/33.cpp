class Solution {
    using vii = vector<int>::iterator;
    vii split(vii first, vii last)
    {
        /*
        首先判断特殊情况：空序列和单调序列
        */
        if(first == last) return last;
        if(*first <= *(last - 1)) return last;
        int tmp = *first;
        /*
        二分查找分界点
        */
        while(first < last - 1)
        {
            auto mid = first + (last - first) / 2;
            if(*mid > tmp) first = mid + 1;
            else last = mid + 1;
            /*
            如果没有这个判断，会出现死循环的情况
            */
            if(*first <= *(last - 1)) break;
            else ++first;
        }
        return first;
    }
public:
    int search(vector<int>& nums, int target) {
        /*
            将nums分成两段单调的序列，二分查找即可。
        */
        auto mid = split(nums.begin(), nums.end());
        /*
            这里可以只用一次二分查找，但可能需要增加判断条件。
        */
        auto it1 = lower_bound(nums.begin(), mid, target),
            it2 = lower_bound(mid, nums.end(), target);
        if(it1 == mid || *it1 != target)
        {
            if(it2 == nums.end() || *it2 != target) return -1;
            return it2 - nums.begin();
        }
        else return it1 - nums.begin();
    }
};