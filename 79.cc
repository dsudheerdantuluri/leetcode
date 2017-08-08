#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool traverse(vector<vector<char>> &board, vector<vector<bool>> &open, int i, int j, string word)
    {
      if (word == "") return true;

      if (open[i][j] == false) return false;

      if (board[i][j] != word[0]) return false;

      bool found = false;

      bool temp = open[i][j];
      open[i][j] = false;

      if (i+1 < board.size())
        found = found || traverse(board, open, i+1, j, word.substr(1, string::npos));

      if (i-1 >= 0)
        found = found || traverse(board, open, i-1, j, word.substr(1, string::npos));

      if (j+1 < board[0].size())
        found = found || traverse(board, open, i, j+1, word.substr(1, string::npos));

      if (j-1 >= 0)
        found = found || traverse(board, open, i, j-1, word.substr(1, string::npos));

      open[i][j] = temp;
      
      return (word.length()==1) || found;

    }

    bool exist(vector<vector<char>>& board, string word)
    {
       if (word.length() == 0) return true;

       if (board.size() == 0) return false;

       auto m = board.size();
       auto n = board[0].size();

       for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
          if (board[i][j] == word[0]) {
            vector<vector<bool>> open(m, vector<bool>(n, true));
            bool found = traverse(board, open, i, j, word);
            if (found) return true;
          }
        }
       }

       return false;
    }
};


int main()
{
	//vector<vector<char>> board{{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}};
	vector<vector<char>> board{{'b','a','b'}};
	Solution s;
	//cout << s.exist(board, "abcced") << endl;
	//cout << s.exist(board, "see") << endl;
	//cout << s.exist(board, "abcb") << endl;
	cout << s.exist(board, "bbabab") << endl;
	return 0;
}
