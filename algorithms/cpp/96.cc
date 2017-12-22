#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int numTrees(int n)
		{
			if ( n <= 1 ) return 1;
			
			vector<int> nt(n+1, 1);

			for (int i=2; i <= n; ++i) {
				int sum = 0;
				for (int j=1; j <= i; ++j) {
			   	sum += nt[j-1] * nt[i-j];
				}
				nt[i] = sum;
			}	
	
			return nt[n];
		}

private:
};

int main()
{
	Solution s;
	cout << s.numTrees(19) << endl;
	return 0;
}
