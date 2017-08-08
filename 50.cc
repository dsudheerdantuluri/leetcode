#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
			
			if (n == 0) {
				return 1;
			}

			if (n == 1) {
				return x;
			} 

			if (n < 0) {
				return 1.0/myPow(x, -n-1)*x;
			}

			auto sr = myPow(x, n/2);

			sr *= sr;

			return n%2 ? sr*x : sr;    
    }
};

int main()
{
	Solution s;
	cout << s.myPow(2,10) << endl;
	cout << s.myPow(1,INT_MIN) << endl;
	return 0;
}
