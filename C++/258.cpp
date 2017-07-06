class Solution {
public:
    int addDigits(int num) {
        // 依次迭代即可
        while(num >= 10)
        {
            int ans=0;
            while(num)
            {
                ans+= num%10;
                num/=10;
            }
            num = ans;
        }
        return num;
    }
};
