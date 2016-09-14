class Solution {
    long long divide(long long dividend, long long divisor) {
        /*
            令 b[] = [1, 2, 4, 8, ...]
            使用移位操作构建 a = divisor * b,
            将dividend从大到小依次与a[i]比较，若dividend较大，
            则减去a[i]，并使result增加b[i]
        */
        bool neg = false;
        if(dividend < 0) dividend = -dividend, neg = !neg;
        if(divisor < 0) divisor = -divisor, neg = !neg;
        vector<long long> vec;
        vec.push_back(divisor);
        while(vec.back() < dividend)
            vec.push_back(vec.back() << 1);
        long long result = 0;
        for(int i = vec.size() - 1; i >= 0; --i)
        {
            if(dividend >= vec[i])
                dividend -= vec[i], result |= 1LL << i;
        }
        if(neg) result = -result;
        return result;
    }
public:
    int divide(int dividend, int divisor) {
        long long result = divide((long long)dividend, (long long)divisor);
        if(result > numeric_limits<int>::max()) return numeric_limits<int>::max();
        return (int)result;
    }
};