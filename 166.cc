#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator) {

			string result("");

			if (denominator == 0) return result;

      if (numerator == 0) {

				result += "0";
	
				return result;

			}

			if ( (numerator < 0) ^ (denominator < 0) ) {
				result += "-";
			}

			auto n = abs(numerator);

			auto d = abs(denominator);

			result += to_string(n / d);

			if ( (n % d) == 0) return result;

			result += ".";

			auto r = n % d;
			
			unordered_map<unsigned int, unsigned int> hash;

			while ( r != 0 ) {

				if (hash.find(r) != hash.end()) {
					result.insert(hash[r],1,'(');
					result += ")";
					break;
				}

				hash[r] = result.length();

				r = r * 10;

				result += to_string(r/d);

				r = r % d;			

			}

			return result;
 
    }
};

int main()
{
  Solution s;
	cout << s.fractionToDecimal(1,2) << endl;	
	cout << s.fractionToDecimal(2,1) << endl;	
	cout << s.fractionToDecimal(2,3) << endl;	
	cout << s.fractionToDecimal(22,7) << endl;	
	cout << s.fractionToDecimal(-1,-2147483648) << endl;

	return 0;
}
