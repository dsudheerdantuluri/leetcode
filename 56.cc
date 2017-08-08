#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	public:
    vector<Interval> merge(vector<Interval>& intervals) 
		{
			vector<Interval> result;

			if (intervals.size() <= 1) {
				return intervals;
			}

			sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){ return a.start < b.start; });

			int rd = 0, wr = 0, ref = 0;
			for ( ; rd < intervals.size(); ++rd) {
				if (intervals[wr].end >= intervals[rd].start) {
					intervals[wr].end = max(intervals[rd].end, intervals[wr].end);
				} else {
					intervals[++wr] = intervals[rd];
				}
			}
			intervals.erase(intervals.begin() + wr + 1, intervals.end());			
	
    	return intervals;    
    }
};

int main()
{
	Solution s;
	vector<Interval> v{{1,30},{2,6},{8,10},{15,18}};
	for (const auto &i: s.merge(v)) {
		cout << "[" << i.start << "," << i.end << "]" << " ";
	}
	cout << endl;
	return 0;
}
