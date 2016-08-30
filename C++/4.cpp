class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
            ����������Ҹĳ�����.....
        */
        int n = nums1.size(), m = nums2.size();
        int k = (n + m + 1) / 2;
        vector<int>::iterator begin1 = nums1.begin(), end1 = nums1.end();
        vector<int>::iterator begin2 = nums2.begin(), end2 = nums2.end();
        vector<int>::iterator mid1;

        /*
            ���ȶ���nums1�����赱ǰλ��Ϊmid����nums2�в���nums1[mid]��upper_bound��
            ����������ֳɴ��ڵ���nums1[mid]��С�ڵ���nums1[mid]�����֣�
            ֱ���������������
            1. �ò���Ϊ�գ�
        */
        while(begin1 < end1)
        {
            mid1 = begin1 + (end1 - begin1) / 2;
            auto it2 = upper_bound(begin2, end2, *mid1);
            int prev_size = (mid1 - begin1) + (it2 - begin2);
            if(k > prev_size) k -= prev_size, begin1 = mid1, begin2 = it2;
            else end1 = mid1, end2 = it2;
            /*
            2. ˵������������
            */
            if(end1 - begin1 == 1 && (end2 - begin2 == 0 || *begin2 > *begin1)) break;
        }
        // tag ��ʾ�м������num1����nums2
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
        // ��֮����
    }
};
