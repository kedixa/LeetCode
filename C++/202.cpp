class Solution {
    // 1 for happy, 2 for not happy
    static vector<int> hp;
    int sqsum(int n) {
        int sum = 0;
        while(n) {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
    void happy(int n) {
        if(hp[n]==1||hp[n]==2) return;
        int sum = sqsum(n);
        if(hp[sum] == 0){
            hp[n] = 3; // 正在查询，防止产生环
            happy(sum);
            hp[n] = hp[sum];
        }
        else if(hp[sum] == 1 || hp[sum] == 2) {
            hp[n] = hp[sum];
        }
        else {
            hp[n] = 2;
        }
    }
public:
    Solution() {
        if(hp.size() == 0) {
            // 打个表
            hp.resize(1000, 0);
            hp[1] = 1, hp[0] = 2;
            for(int i = 0; i < 1000; ++i) {
                if(hp[i] == 0) happy(i);
            }
        }
    }
    bool isHappy(int n) {
        return hp[sqsum(n)]==1;
    }
};
vector<int> Solution::hp;
