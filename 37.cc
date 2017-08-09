// lt37.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution {
private:
	vector<char> getCandidates(vector<vector<char>> &board, int row, int col)
	{
		array<bool, 9> lookup;
		fill(lookup.begin(), lookup.end(), true);

		vector<char> result;
		for (auto r = 0; r < 9; ++r) {
			if (board[r][col] != '.') {
				auto index = board[r][col] - '1';
				lookup[index] = false;
			}
		}

		for (auto c = 0; c < 9; ++c) {
			if (board[row][c] != '.') {
				auto index = board[row][c] - '1';
				lookup[index] = false;
			}
		}

		auto r = row / 3;
		auto c = col / 3;
		for (auto i = r * 3; i < r * 3 + 3; ++i) {
			for (auto j = c * 3; j < c * 3 + 3; ++j) {
				if (board[i][j] != '.') {
					auto index = board[i][j] - '1';
					lookup[index] = false;
				}
			}
		}

		for (auto i = 0; i < 9; ++i) {
			if (lookup[i]) {
				result.emplace_back('1' + i);
			}
		}

		return result;
	}

	void print(vector<vector<char>> &b)
	{
		for (auto row : b) {
			for (auto col : row) {
				cout << col << " ";
			}
			cout << endl;
		}
	}

	bool solveSudoku(vector<vector<char>> board, int row, int col, vector<vector<char>> &final)
	{		
		if (board[row][col] == '.') {
			auto cands = getCandidates(board, row, col);
			bool solved = false;			
			for (auto cand : cands) {
				board[row][col] = cand;				
				if (row != 8 || col != 8) {
					solved = solved || solveSudoku(board, (col == 8) ? row + 1 : row, (col == 8) ? 0 : col + 1, final);
					if (solved) {						
						return true;
					}
				}
				else {
					final = board;					
					return true;
				}
			}
		}
		else {
			if (row != 8 || col != 8) {
				return solveSudoku(board, (col == 8) ? row + 1 : row, (col == 8) ? 0 : col + 1, final);
			}
			else {
				final = board;
				return true;
			}
		}

		return false;
	}

public:
	void solveSudoku(vector<vector<char>>& board)
	{
		solveSudoku(board, 0, 0, board);
	}
};

int main()
{
	Solution s;
	
		 vector<vector<char>> b({ 
			                    { '.','.','9','7','4','8','.','.','.' },
								{ '7','.','.','.','.','.','.','.','.' },
								{ '.','2','.','1','.','9','.','.','.' },
								{ '.','.','7','.','.','.','2','4','.' },
								{ '.','6','4','.','1','.','5','9','.' },
								{ '.','9','8','.','.','.','3','.','.' },
								{ '.','.','.','8','.','3','.','2','.' },
								{ '.','.','.','.','.','.','.','.','6' },
								{ '.','.','.','2','7','5','9','.','.' }
	                          });
		 s.solveSudoku(b);

		 for (auto row : b) {
			 for (auto col : row) {
				 cout << col << " ";
			 }
			 cout << endl;
		 }
    return 0;
}

