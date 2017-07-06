class Solution {
public:
    int countDigitOne(int n) {
        // 依次判断每个数位上的1的个数，
        // 例如32145中第三个数位上1的个数，不但和前面的(32)有关，
        // 和后面的(45)有关，还和该数位与1的关系有关
        if(n < 0) return 0;
        int p = n, q = 0, t = 1;
        int sum = 0;
        while(p) {
            int k = p % 10;
            p /= 10;
            sum += t * p;
            if(k == 1) sum += (q + 1);
            else if (k > 1) sum += t;
            q += t * k;
            t *= 10;
        }
        return sum;
    }
};
