#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) 
		{
			if (digits.size() == 0) 
				return digits;

			bool carry = true;
			for (int i = digits.size()-1; i>=0; --i) {
				auto s = digits[i]+carry;
				digits[i] = s%10;
				carry = s/10; 
			}
		
			if (carry)
				digits.insert(digits.begin(), 1);
	
			return digits;
		}
};

int main()
{
	Solution s;
	vector<int> v1{1,2,3};
	for (auto e:s.plusOne(v1))
		cout << e << " ";
	cout << endl;
	vector<int> v2{9,9,8};
	for (auto e:s.plusOne(v2))
		cout << e << " ";
	cout << endl;
	vector<int> v3{9,9,9};
	for (auto e:s.plusOne(v3))
		cout << e << " ";
	cout << endl;
	return 0;
}
