class Solution {
public:

    static bool cmp(Interval &a, Interval &b){
        return a.start < b.start;
    }

    bool canAttendMeetings(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(), cmp);

        for(int i = 0; i + 1 < intervals.size(); i++){

            if(intervals[i].end > intervals[i+1].start){
                return false;
            }
        }

        return true;
    }
};