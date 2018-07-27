class Solution {
public:
    struct{
        bool operator()(Interval i1, Interval i2){
            return i1.start<i2.start;
        }
    } Compare;
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>::iterator iter = lower_bound(intervals.begin(), intervals.end(), newInterval, Compare);
        
        vector<Interval>::iterator new_iter;
        if(iter-intervals.begin()-1>=0 && (iter-1)->end>=newInterval.start){
            (iter-1)->end = max((iter-1)->end, newInterval.end);
            new_iter = iter-1;
        }else{
            iter = intervals.insert(iter, newInterval);
            new_iter = iter;
            iter++;
        }
        
        while (iter!=intervals.end() && iter->start<=new_iter->end) {
            iter++;
        }
        new_iter->end = max((iter-1)->end, new_iter->end);
        if(iter-new_iter>1) intervals.erase(new_iter+1, iter);
        
        return intervals;
    }
};
