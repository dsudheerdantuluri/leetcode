#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {   
      vector<int> sums(triangle.size(), 0); 

      for (auto row = 0; row < triangle.size(); ++row) {
        vector<int> prevSums(sums);
        for (auto col = 0; col <= row; ++col) {
          sums[col] = triangle[row][col];
          auto val = ((col-1) >= 0) ? prevSums[col-1]: prevSums[col];
          if (col <= row-1) val = min(val, prevSums[col]);
          sums[col] += val;
        }
      }   

      return *min_element(sums.begin(), sums.end());  
    }   
};

int main()
{
	Solution s;
	vector<vector<int>> v{{-1},{2,3},{1,-1,-3}};
	cout << s.minimumTotal(v) << endl;
	return 0;
}
