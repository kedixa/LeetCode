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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        /*
            先将newInterval放到正确的位置，然后将它与前后合并。
        */
        auto cmp = [](Interval a, Interval b){
            if(a.start == b.start) return a.end < b.end;
            else return a.start < b.start;
        };
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval, cmp);
        it = intervals.insert(it, newInterval);
        if(it != intervals.begin() && (*(it - 1)).end >= (*it).start) --it;
        auto it2 = it;
        newInterval = *it2;
        for(; it2 != intervals.end(); ++it2)
        {
            if((*it2).start <= newInterval.end)
                newInterval.end = max(newInterval.end, (*it2).end), *it2 = Interval(-1, -1);
            else break;
        }
        *it = newInterval;
        intervals.erase(
            remove_if(it, intervals.end(), [](Interval &v){
                return v.start == -1 && v.end == -1;}
            ),
            intervals.end()
        );
        return intervals;
    }
};