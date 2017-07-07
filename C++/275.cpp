class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = citations.size();
        if(sz == 0) return 0;
        const auto &c = citations;
        int low = 0, high = sz - 1, mid;
        while(low < high) {
            mid = (low + high) / 2;
            if(c[mid] < sz - mid)
                low = mid + 1;
            else high = mid;
        }
        if(c[low] >= sz - low)
            return sz - low;
        else return 0;
    }
};
