class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int sz = citations.size();
        for(int i = 0; i < sz; ++i) {
            if(citations[i] >= sz - i)
                return sz - i;
        }
        return 0;
    }
};
