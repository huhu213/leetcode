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
        if(intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int length = intervals.size();
        vector<Interval> result;
        if(newInterval.end < intervals[0].start) {
            cout << "test" << endl;
            result.push_back(newInterval);
            for(int i = 0; i < length; i ++) result.push_back(intervals[i]);
            return result;
        }
        if(newInterval.end == intervals[0].start) {
            intervals[0].start = newInterval.start;
            return intervals;
        }
        if(newInterval.start == intervals[length-1].end) {
            intervals[length-1].end = newInterval.end;
            return intervals;
        }
        if(newInterval.start > intervals[length-1].end) {
            intervals.push_back(newInterval);
            return intervals;
        }

        int s = 0;
        while(s < length && intervals[s].end < newInterval.start) {
            result.push_back(intervals[s]);
            s ++;
        }
        cout << s << " ";
        int e = s;
        while(e < length && intervals[e].start <= newInterval.end) e ++;

        cout << e << endl;
        newInterval.start = min(intervals[s].start, newInterval.start);
        newInterval.end = max(intervals[e-1].end, newInterval.end);
        result.push_back(newInterval);
        cout << result.size() << endl;
        for(int i = e; i < length; i ++) result.push_back(intervals[i]);
        return result;   
    }
};