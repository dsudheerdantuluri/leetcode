#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) 
		{
       if (n<=2) return n;

			 auto a = 1, b = 2;
			 for (auto i=3; i<=n; ++i) {
			 	a=a+b;
			  swap(a,b);
			 }

			return b; 
    }
};

int main()
{
	Solution s;
	cout << s.climbStairs(1) << endl;
	cout << s.climbStairs(2) << endl;
	cout << s.climbStairs(3) << endl;
	cout << s.climbStairs(4) << endl;
	cout << s.climbStairs(5) << endl;
	return 0;
}
