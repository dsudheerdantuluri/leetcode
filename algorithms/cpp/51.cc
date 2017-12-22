#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
	private:
		bool canPutQueen(const vector<pair<int, int>> &eqp, int i, int j) const
		{
			//cout << "canPutQueen(" << i << "," << j << "):";
			for (const auto &p : eqp) {
				if ( (p.first == i) || (p.second == j) || (abs(p.first-i)==abs(p.second-j)) ) { 
					//cout << "false" << endl;
					return false;
				}   
			}   
			//cout << "true" << endl;
			return true;  
		}

		void solveNQueens(int n, vector<string> &board, vector<vector<string>> &result, vector<pair<int, int>> &eqp, int ci) 
		{
			if (ci == n) {
				result.emplace_back(board);
				return;
			}   

			for (auto i=ci; i<n ; ++i) {
				bool found = false;
				for (auto j=0; j<n ; ++j) {
					if (canPutQueen(eqp, i, j)) {
						board[i][j] = 'Q';
						//cout << "ci:" << ci << " i:"<< i << " j:" << j << endl;
						eqp.emplace_back(pair<int,int>(i,j));
						solveNQueens(n, board, result, eqp, ci+1);
						found = true;
						eqp.pop_back();
						board[i][j] = '.';
					}
				}
				if (!found) {
					return;
				}
			}   
		}

	public:
		vector<vector<string>> solveNQueens(int n)  
		{   
			vector<vector<string>> result;

			vector<string> board(n, string(n,'.'));

			vector<pair<int, int>> eqp;
			eqp.reserve(n);

			solveNQueens(n, board, result, eqp, 0); 

			return result;
		}   
};


int main()
{
	Solution s;
	
	for (const auto &vs :	s.solveNQueens(4)) {
		for (const auto &s : vs) {
			cout << s << endl;
		}
		cout << "--" << endl;
	}

	return 0;
}
