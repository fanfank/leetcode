/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval &a, const Interval &b) {
    return a.start!=b.start?a.start < b.start:a.end < b.end;
}
class Solution {
public:
    vector<Interval> v;
    vector<Interval> merge(vector<Interval> &intervals) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(intervals.size() < 2)
            return intervals;
        v.clear();
        sort(intervals.begin(), intervals.end(), cmp);
        Interval itv(intervals[0].start, intervals[0].end);
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start <= itv.end) {
                itv.end = max(itv.end, intervals[i].end);
            } else {
                v.push_back(itv);
                itv.start = intervals[i].start;
                itv.end = intervals[i].end;
            }
        }
        v.push_back(itv);
        return v;
    }
};