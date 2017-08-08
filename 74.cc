#include <iostream>
#include <vector>

using namespace std;

class Solution {
	private:
		template<typename l>
		int bs(vector<vector<int>>& matrix, int low, int high, int target, l f)
		{
			if (low > high) return -1;

			auto mid = low + (high-low)/2;
			auto res = f(matrix, mid, target);
			if (res == 0) return mid;
			else if (res < 0) return bs(matrix, low, mid-1, target, f);
			else return bs(matrix, mid+1, high, target, f);
		}

	public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
		{
			if (!matrix.size()) return false;
			if (!matrix[0].size()) return false;

			auto p1 = [](vector<vector<int>>& matrix, int mid, int target) {
										if (matrix[mid][0]<=target && ((mid ==  matrix.size()-1) || matrix[mid+1][0]>target)) return 0;
										else if (matrix[mid][0] > target) return -1;
										else return 1;
									};

			auto row = bs(matrix, 0, matrix.size()-1, target, p1);

			auto p2 = [row](vector<vector<int>>& matrix, int mid, int target) {
										if (matrix[row][mid]==target) return 0;
										else if (matrix[row][mid] > target) return -1;
										else return 1;
									};
			
 
			return (row == -1) ? false : (bs(matrix, 0, matrix[row].size()-1, target, p2) != -1);
    }
};

int main()
{
	Solution s;
	vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	for (int i = 1; i <= 51; ++i ) {
		cout << i << ":" << s.searchMatrix(matrix, i) << endl;
	}
	return 0;
}
