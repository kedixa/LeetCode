/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        /*
            按cmp指定的顺序排序，若相邻的两段可以合并，则合并。
        */
        auto cmp = [](Interval &a, Interval &b){
            if(a.start == b.start) return a.end < b.end;
            else return a.start < b.start;
        };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> result;
        if(intervals.size() == 0) return result;
        Interval val = intervals[0];
        for(int i = 1; i < intervals.size(); ++i)
        {
            auto &k = intervals[i];
            if(k.start <= val.end) val.end = max(val.end, k.end);
            else result.push_back(val), val = k;
        }
        result.push_back(val);
        return result;
    }
};