#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      unordered_map<int, unordered_set<int>> pg; 
      for (const auto &p : prerequisites) pg[p.first].insert(p.second);
      vector<bool> track(numCourses, false);
      vector<bool> seen(numCourses, false);
      for (const auto &p : prerequisites) {
        if ((!seen[p.first]) && hasCycle(p.first, seen, track, pg)) return false;
      }   
      return true;
    }   
    bool hasCycle(int s, vector<bool> &seen, vector<bool> &track, unordered_map<int, unordered_set<int>> &pg)  {
			if (track[s]) return true;
			if (seen[s]) return false;
      seen[s] = track[s] = true;
			unordered_set<int> &dv = pg[s];
      for (auto d: dv) {
        if (hasCycle(d, seen, track, pg)) {
					track[s] = false;
					return true;
				}
      }   
      track[s] = false;
      return false;
    }   
};

int main()
{
	Solution s;
	vector<pair<int,int>> vp{{0,1},{3,1},{1,3},{3,2}};
	cout << s.canFinish(4, vp) << endl;
	return 0;
}
