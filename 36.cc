// lt36.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
private:
	bool updateLookup(vector<vector<char>>& board, std::array<bool, 9> lookup, int row, int col)
	{
		if (board[row][col] == '.') {
			return true;
		}
		if (lookup[board[row][col]]) {
			return false;
		}
		
		lookup[board[row][col]] = true;
		return true;
	}

public:
	bool isValidSudoku(vector<vector<char>>& board) 
	{
		std::array<bool, 9> lookup;
		for (auto row = 0; row < 9; ++row) {
			fill(lookup.begin(), lookup.end(), false);
			for (auto col = 0; col < 9; ++col) {
				if (!updateLookup(board, lookup, row, col)) {
					return false;
				}
			}
		}

		for (auto col = 0; col < 9; ++col) {
			fill(lookup.begin(), lookup.end(), false);
			for (auto row = 0; row < 9; ++row) {
				if (!updateLookup(board, lookup, row, col)) {
					return false;
				}
			}
		}

		for (auto i = 0; i < 9; i += 3) {
			for (auto j = 0; j < 9; j += 3) {
				fill(lookup.begin(), lookup.end(), false);
				for (auto row = i; row < i + 3; ++row) {
					for (auto col = j; col < j + 3; ++col) {
						if (!updateLookup(board, lookup, row, col)) {
							return false;
						}
					}
				}
			}
		}

		return true;
	}
};

int main()
{
    return 0;
}

