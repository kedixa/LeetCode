class Solution {
    vector<int> fac;
public:
    Solution()
    {
        /*
            预先计算i的阶乘。
        */
        fac.resize(10);
        fac[0] = 1;
        for(int i = 1; i < 10; ++i) fac[i] = i * fac[i - 1];
    }
    string getPermutation(int n, int k) {
        /*
            从前到后一位一位地生成
            mark记录已经使用的数
        */
        vector<bool> mark(n + 1, false);
        string result;
        for(int i = 1; i <= n; ++i)
        {
            /*
            找第一个未使用的位
            */
            int index = 1;
            while(mark[index]) index++;
            /*
            每当k>(n-1)!，则找下一个可以使用的位
            */
            while(k > fac[n - i])
            {
                index++;
                while(mark[index]) index++;
                k -= fac[n - i];
            }
            mark[index] = true;
            result += (char)(index + '0');
        }
        return result;
    }
};