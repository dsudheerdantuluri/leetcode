#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
		{
    	int m = matrix.size();

			if (m==0) return 0;

			int n = matrix[0].size();

			if (n==0) return 0;

			vector<int> left(n,0), right(n,n), height(n,0);
			int mra = 0;

			for (int i=0; i<m; ++i) {

				int curLeft = 0, curRight = n;

				for (int j=0; j<n; ++j) {
					if (matrix[i][j] == '1') height[j]++;
          else height[j] = 0;		
				}

				for (int j=0; j<n; ++j) {
					if (matrix[i][j] == '1') left[j] = max(left[j], curLeft); 
          else { left[j] = 0; curLeft = j+1; }	
				}

				for (int j=n-1; j>=0; --j) {
					if (matrix[i][j] == '1') right[j] = min(right[j], curRight); 
          else { right[j] = n; curRight = j; }	
				}

				for (int j=0; j<n; ++j) {
					mra = max(mra, (right[j]-left[j])*height[j]);
				}
			
			}

			return mra; 
    }
};

int main()
{
	vector<vector<char>> matrix{{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1', '0', '0', '1', '0'} };
	Solution s;
  cout << s.maximalRectangle(matrix) << endl;
	return 0;
}
