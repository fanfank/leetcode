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
    vector<Interval> v;
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(intervals.empty())
            return vector<Interval>(1, newInterval);
        v.clear();
        for(int i = 0; i < intervals.size(); ++i) {
            if(newInterval.start <= intervals[i].end) {
                if(newInterval.start > intervals[i].start)
                    swap(newInterval, intervals[i]);
                v.push_back(newInterval);
                for(int j = i; j < intervals.size(); ++j) {
                    if(intervals[j].start > v.back().end) {
                        v.push_back(intervals[j]);
                    } else {
                        v.back().end = max(v.back().end, intervals[j].end);
                    }
                }
                return v;
            } else {
                v.push_back(intervals[i]);
            }
        }
        v.push_back(newInterval);
        return v;
    }
};