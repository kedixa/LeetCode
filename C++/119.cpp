class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> result;
        result.resize(rowIndex);
        result[0] = 1;
        long long s = 1;
        for(int i = 1; i < rowIndex; ++i)
        {
            s *= (rowIndex - i);
            s /= i;
            result[i] = s;
        }
        return result;
    }
};
