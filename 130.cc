#include <iostream>
#include <vector>

using namespace std;

class Solution {
		void check(vector<vector<char>> &board, int i, int j, int m, int n)
		{
			if ( board[i][j] != 'O') return;

			board[i][j] = 'P';

			if (i < m) check(board, i+1, j, m, n);
			if (i > 0) check(board, i-1, j, m, n);
			if (j < n) check(board, i, j+1, m, n);
			if (j > 0) check(board, i, j-1, m, n);
		}
	
public:
    void solve(vector<vector<char>>& board) 
		{
			if (board.size() < 2) return;
			
			if (board[0].size() < 2) return;

			int m = board.size() - 1;

			int n = board[0].size() - 1;

			for ( int i = 0 ; i <= m ; ++i ) {
				if ( board[i][0] == 'O' ) check(board, i, 0, m, n);
				if ( (n > 0) && (board[i][n] == 'O') )	check(board, i, n, m, n);
			}

			for ( int i = 0 ; i <= n ; ++i ) {
				if ( board[0][i] == 'O' ) check(board, 0, i, m, n);
				if ( (m > 0) && (board[m][i] == 'O') ) check(board, m, i, m, n);
			}

			for ( int i = 0 ; i <= m ; ++i ) {
				for ( int j = 0 ; j <= n ; ++j ) {
					if ( board[i][j] == 'O' ) board[i][j] = 'X'; 
					else if ( board[i][j] == 'P' ) board[i][j] = 'O';
				}
			}
    }
};

int main()
{

}
