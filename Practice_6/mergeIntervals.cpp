#include<bits/stdc++.h>
using namespace std;

class Interval{
    public:
    int start, end;
};
bool comparator(const Interval &a, const Interval &b){
    return a.start < b.start;
}

vector<Interval> mergeIntervals(vector<Interval> &intervals){
    sort(intervals.begin(), intervals.end(),comparator);
    vector<Interval> result;
    result.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(result.back().end < intervals[i].start){
            result.push_back(intervals[i]);
        }
        else
        {
            result.back().end = max(result.back().end, intervals[i].end);
        }
    }
    return result;
}

int main()
{
    vector<Interval> interval={{7,8}, {1,2},{2,4},{4,6}};
    vector<Interval> ans = mergeIntervals(interval);
    for(int i=0;i<ans.size();i++)
    {
        cout<<"["<<ans[i].start<<","<<ans[i].end<<"] ";
    }
}