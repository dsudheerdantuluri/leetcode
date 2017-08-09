#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) 
		{
			 string result("");
	
			 bool carry = false;
			 
			 using strRevIt = std::string::reverse_iterator;
			 strRevIt aIt, bIt;
		
			 for (aIt = a.rbegin(), bIt = b.rbegin(); 
					 aIt != a.rend() && bIt != b.rend(); ++aIt, ++bIt) {
				 auto sum = (*aIt == '1' ^ *bIt == '1');
				 auto c = (*aIt == '1' && *bIt == '1');
				 sum = sum ^ carry;
				 carry = ((*aIt == '1' || *bIt=='1') && carry) || c;
				 result += sum ? "1" : "0";
			 }

			 while (aIt != a.rend()) {
			 	auto sum = (*aIt == '1') ^ carry;
				carry = (*aIt == '1') && carry;	
				result += sum ? "1" : "0";
				++aIt;
			 }
			 
			 while (bIt != b.rend()) {
			 	auto sum = (*bIt == '1') ^ carry;
				carry = (*bIt == '1') && carry;	
				result += sum ? "1" : "0";
				++bIt;
			 }

			 if (carry) result += "1";

			 reverse(result.begin(), result.end());

			 return result;
    }
};

int main()
{
	Solution s;
	cout << s.addBinary("11","1") << endl;
	cout << s.addBinary("1010","1011") << endl;
	return 0;
}
