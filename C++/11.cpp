class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int s = 0, t = height.size() - 1;
        while(s < t)
        {
            max_area = max(max_area, (t - s) * min(height[s], height[t]));
            if(height[s] <= height[t]) ++s;
            else --t;
        }
        return max_area;
    }
};
