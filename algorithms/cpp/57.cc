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

	private:

		bool overlap(const Interval &a, const Interval &b)
		{
			return (a.start >= b.start && a.start <= b.end) || (b.start >= a.start && b.start <= a.end);
		}

	public:
    vector<Interval> merge(vector<Interval>& intervals) 
		{
			vector<Interval> result;

			if (intervals.size() <= 1) {
				return intervals;
			}

			//sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){ return a.start < b.start; });

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

		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
		{
			auto pos = find_if(intervals.begin(), intervals.end(), [&newInterval](const Interval &ref){ return newInterval.start < ref.start; });
			intervals.insert(pos, newInterval);
	
			return merge(intervals); 
		}
};

int main()
{
	Solution s;
	//vector<Interval> v{{1,2},{3,5},{6,7},{8,10},{12,16}};
	//Interval in{4,9};
	vector<Interval> v{{1,2},{3,5},{6,7},{8,10},{12,16}};
	Interval in{4,9};
	for (const auto &i: s.insert(v,in)) {
		cout << "[" << i.start << "," << i.end << "]" << " ";
	}
	cout << endl;
	return 0;
}
