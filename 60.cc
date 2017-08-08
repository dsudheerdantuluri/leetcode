#include <iostream>

using namespace std;

class Solution 
{
	private:
		int factorial(int n) 
		{
			return n <= 1 ? 1 : n * factorial(n-1);
		}

	public:
		string getPermutation(int n, int k) 
		{
			string nstr(n, '0'), result("");
			for ( auto i = 1; i <= n; ++i) {
				nstr[i-1] = '0' + i;
			}

			while (n > 0) {
				auto nfac = factorial(n);
				auto q = nfac/n;
				auto pos = (k-1)/q;
				result += nstr.substr(pos,1);
				nstr.erase(pos,1);
				n -= 1;	 
				k -= pos*q; 
			}

			result += nstr;
			
			return result;
		}
};

int main()
{	
	Solution s;
	cout << s.getPermutation(1, 1) << endl;	
	cout << s.getPermutation(2, 1) << endl;	
	cout << s.getPermutation(2, 2) << endl;	
	cout << s.getPermutation(3, 10) << endl;	
	cout << s.getPermutation(3, 2) << endl;	
	cout << s.getPermutation(3, 3) << endl;	
	cout << s.getPermutation(3, 4) << endl;	
	cout << s.getPermutation(3, 5) << endl;	
	cout << s.getPermutation(3, 6) << endl;	
}
/*
class Solution 
{
	private:
		int factorial(int n) 
		{
			return n <= 1 ? 1 : n * factorial(n-1);
		}

	public:
		string getPermutation(int n, int k) 
		{
			string nstr(n, '0'), result("");
			for ( auto i = 1; i <= n; ++i) {
				nstr[i-1] = '0' + i;
			}
			//cout << nstr << endl;
			while (n > 0) {
				auto nfac = factorial(n);
				//cout << "nfac:" << nfac << endl;
				auto q = nfac/n;
				//cout << "q:" << q << endl;
				auto pos = (k-1)/q;
				//cout << "pos:" << pos << endl;
				result += nstr.substr(pos,1);
				//cout << "result:" << result << endl;
				nstr.erase(pos,1);
				//cout << "nstr:" << nstr << endl;
				n -= 1;	 
				//cout << "n:" << n << endl;
				k -= pos*q; 
				//cout << "k:" << k << endl;
			}

			result += nstr;
			return result;
		}
};*/
