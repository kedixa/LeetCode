// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // 二分法
        int low = 1, high = n, mid;
        while(low < high) {
            mid = low + (high - low) / 2;
            if(isBadVersion(mid))
                high = mid;
            else low = mid + 1;
        }
        if(isBadVersion(low)) return low;
        else return low + 1;
    }
};
