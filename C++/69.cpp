class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0; // 0 需要特判
        /*
            使用二分法求解
            一个需要注意的点是乘法不能乱用，其他的没有了。
        */
        int left = 1, right = x / 2 + 1, mid;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(x / mid < mid) right = mid - 1;
            else if(x / mid >= mid)
            {
                left = mid;
                if(x - mid * mid - 2 * mid - 1 >= 0) left += 1;
                else right = mid;
            }
        }
        return left;
    }
};