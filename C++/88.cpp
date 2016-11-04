class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 有序序列，每次取出max(max(nums1), max(nums2))，复杂度为O(n)
        auto it1 = nums1.rend() - m - n, it2 = nums1.rend() - m, it3 = nums2.rend() - n;
        while(it2 != nums1.rend() && it3 != nums2.rend())
        {
            if(*it2 < *it3) *it1 = *it3++;
            else *it1 = *it2++;
            ++it1;
        }
        while(it2 != nums1.rend()) *it1++ = *it2++;
        while(it3 != nums2.rend()) *it1++ = *it3++;
    }
};