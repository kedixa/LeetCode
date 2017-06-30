class Solution {
public:
    int hammingWeight(uint32_t n) {
        static const uint32_t C[] = {
            0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4
        };
        static const uint32_t mask = 0xF;
        int r = 0;
        for(int i = 0; i < 32; i+=4)
            r += C[(n>>i)&mask];
        return r;
    }
};
