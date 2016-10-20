class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /*
            逐位相加即可
        */
        auto it = digits.rbegin();
        vector<int> result;
        result.reserve(digits.size() + 1);
        int carry = 1;
        while(it != digits.rend())
        {
            carry += *it++;
            if(carry > 9) result.push_back(carry - 10), carry = 1;
            else result.push_back(carry), carry = 0;
        }
        if(carry) result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};