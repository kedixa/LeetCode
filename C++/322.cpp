class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> v(amount + 1, 12345678);
        v[0] = 0;
        for(auto c : coins) {
            for(int j = 0; j < amount + 1 - c; j++) {
                if(v[j + c] > v[j] + 1)
                    v[j + c] = v[j] + 1;
            }
        }
        if(v[amount] > amount)
            return -1;
        else return v[amount];
    }
};
