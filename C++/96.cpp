class Solution {
    vector<int> vec;
public:
    Solution() {
        vec.push_back(1);
        for(int i = 1; i < 20; i++)
        {
            vec.push_back(0);
            for(int j = 0; j < i; j++)
                vec[i] += vec[j] * vec[i - j - 1];
        }
    }
    int numTrees(int n) {
        return vec[n];
    }
};
