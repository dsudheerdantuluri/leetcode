#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
	
	private:
		bool canPutQueen(const vector<pair<int, int>> &eqp, int i, int j) const
		{
			for (const auto &p : eqp) {
				if ( (p.first == i) || (p.second == j) || (abs(p.first-i)==abs(p.second-j)) ) { 
					return false;
				}   
			}   
			return true;  
		}
	
		void solveNQueens(int n, vector<vector<bool>> &board, int &result, vector<pair<int, int>> &eqp, int ci) 
		{
			if (ci == n) {
				result++;	
				return;
			}   

			for (auto i=ci; i<n ; ++i) {
				bool found = false;
				for (auto j=0; j<n ; ++j) {
					if (canPutQueen(eqp, i, j)) {
						board[i][j] = true;
						eqp.emplace_back(pair<int,int>(i,j));
						solveNQueens(n, board, result, eqp, ci+1);
						found = true;
						eqp.pop_back();
						board[i][j] = false;
					}
				}
				if (!found) {
					return;
				}
			}   
		}
	
	public:
		int totalNQueens(int n) 
		{

			int count = 0;			

			vector<vector<bool>> board(n, vector<bool>(n,false)); 

			vector<pair<int, int>> eqp;
			eqp.reserve(n);

			solveNQueens(n, board, count, eqp, 0); 

			return count;
		}   
};

int main()
{
	Solution s;

	cout << s.totalNQueens(8) << endl;
	
	return 0;
}
