#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
			int lra = 0;

			stack<int> s;

			int i = 0;

			while (i<heights.size()) {
				if (s.empty() || heights[i] >= heights[s.top()]) {
					s.push(i++);
				} else {
					auto h = s.top();
					s.pop();
					lra = max(lra, (s.empty() ? i : i-s.top()-1) * heights[h]);
				}
			}

			while (!s.empty()) {
				auto h=s.top();
				s.pop();
				lra = max(lra, (s.empty() ? i : i-s.top()-1) * heights[h]);
			}

			return lra;
    }
};

int main()
{
	vector<int> h{2,1,5,6,2,3};
	Solution s;
	cout << s.largestRectangleArea(h) << endl;	
	return 0;
}
