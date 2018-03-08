class Solution {
    vector<int> maxvec(vector<int> &v, int k) {
        int n = v.size();
        vector<int> vi(k, -1);
        for(int i = 0, j = 0; i < n; ++i) {
            while(n - i + j > k && j > 0 && vi[j - 1] < v[i]) --j;
            if(j < k) vi[j++] = v[i];
        }
        return vi;
    }
    vector<int> merge(const vector<int> &v1, const vector<int> &v2) {
        int n1 = v1.size(), n2 = v2.size();
        int i = 0, j = 0;
        vector<int> v;
        v.reserve(n1 + n2);
        while(i < n1 && j < n2) {
            if(v1[i] > v2[j])
                v.push_back(v1[i++]);
            else if(v1[i] < v2[j])
                v.push_back(v2[j++]);
            else {
                int a = i, b = j;
                while(a < n1 && b < n2 && v1[a] == v2[b]) ++a, ++b;
                if(a == n1) v.push_back(v2[j++]);
                else if(b == n2) v.push_back(v1[i++]);
                else if(v1[a] > v2[b]) v.push_back(v1[i++]);
                else v.push_back(v2[j++]);
            }
        }
        while(i < n1) v.push_back(v1[i++]);
        while(j < n2) v.push_back(v2[j++]);
        return v;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result;
        int m = nums1.size(), n = nums2.size();
        for(int i = 0; i <= m; i++) {
            if(k - i < 0) break;
            if(k - i > n) continue;
            auto tmp = merge(maxvec(nums1, i), maxvec(nums2, k - i));
            if(result < tmp)
                result = tmp;
        }
        return result;
    }
};
