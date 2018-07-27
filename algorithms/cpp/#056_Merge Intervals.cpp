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
    struct {
        bool operator()(Interval i1, Interval i2){
            return i1.end < i2.end;
        }
    } Compare;
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), Compare);
        
        for (int i=(int)intervals.size()-1; i>0; i--) {
            if(intervals[i].start<=intervals[i-1].end){
                intervals[i].start = min(intervals[i].start, intervals[i-1].start);
                intervals.erase(intervals.begin()+i-1);
            }
        }
        
        return intervals;
    }
};
