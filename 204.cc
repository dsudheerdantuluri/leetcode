#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
			vector<bool> np(n+1, true);
			np[0] = np[1] = false;
			int count = 0;
			for (int i = 2; i < n; ++i) {
				if (np[i] == false) continue;
				for (int j = 2; j*i <= n; ++j)
					np[j*i] = false;
				++count;
			}
			return count;
		}
};

int main()
{
	return 0;
}

