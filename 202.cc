#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
			set<int> s;
			s.insert(n);
			while ( n != 1 ) {
				auto k = n;
				auto sum = 0;
				while ( k != 0 ) {
					auto rem = k%10;
					sum += (rem * rem);
					k = k/10;
				}
				n = sum;
				auto it = s.find(n);
				if ( it == s.end() ) s.insert(n);
				else break;
			}
			return (n==1);	
    }
};

int main()
{
	return 0;
}
