class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
            这个题是我乱改出来的.....
        */
        int n = nums1.size(), m = nums2.size();
        int k = (n + m + 1) / 2;
        vector<int>::iterator begin1 = nums1.begin(), end1 = nums1.end();
        vector<int>::iterator begin2 = nums2.begin(), end2 = nums2.end();
        vector<int>::iterator mid1;

        /*
            首先二分nums1，假设当前位置为mid，在nums2中查找nums1[mid]的upper_bound，
            将两个数组分成大于等于nums1[mid]和小于等于nums1[mid]两部分，
            直到出现下述情况：
            1. 该部分为空；
        */
        while(begin1 < end1)
        {
            mid1 = begin1 + (end1 - begin1) / 2;
            auto it2 = upper_bound(begin2, end2, *mid1);
            int prev_size = (mid1 - begin1) + (it2 - begin2);
            if(k > prev_size) k -= prev_size, begin1 = mid1, begin2 = it2;
            else end1 = mid1, end2 = it2;
            /*
            2. 说不清楚的情况。
            */
            if(end1 - begin1 == 1 && (end2 - begin2 == 0 || *begin2 > *begin1)) break;
        }
        // tag 表示中间的数在num1还是nums2
        int tag;
        if(end1 - begin1 == 1)
        {
            if(k == 1) tag = 1, mid1 = begin1;
            else tag = 2, mid1 = begin2 + k - 2;
        }
        else tag = 2, mid1 = begin2 + k - 1;
        if((n + m) % 2 != 0) return static_cast<double>(*mid1);
        else
        {
            double sum = *mid1;
            vector<int>::iterator mid2;
            if(tag == 1)
            {
                mid2 = begin2;
                if(mid2 == nums2.end()) sum += *(mid1 + 1);
                else if(mid1 + 1 == nums1.end()) sum += *mid2;
                else sum += min(*(mid1 + 1), *mid2);
            }
            else
            {
                mid2 = lower_bound(end1, nums1.end(), *mid1);
                if(mid2 == nums1.end()) sum += *(mid1 + 1);
                else if(mid1 + 1 == nums2.end()) sum += *mid2;
                else sum += min(*(mid1 + 1), *mid2);
            }
            return sum / 2.0;
        }
        // 总之很乱
    }
};
