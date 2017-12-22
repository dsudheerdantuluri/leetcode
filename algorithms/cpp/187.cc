#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
		{
			unordered_map<char, int> hash{{'A',1},{'G',2},{'C',3},{'T',4}};

			unordered_map<unsigned int, string> seqs;

			unsigned long long int num = 0;

			set<string> result;

			for ( int i = 0; i < s.length(); ++i ) {

				if ( i < 9 ) {

					num = num * 10 + hash[s[i]];

				}	else {

					num = num % 1000000000;
					num = num * 10 + hash[s[i]];
					auto it = seqs.find(num);

					if ( it != seqs.end() ) {
						result.insert(it->second); 
					} else {
						seqs[num] = s.substr(i-9, 10);
					}
				}
			}

			return vector<string>(result.begin(), result.end());
    }
};

int main()
{
	Solution s;

	vector<string> result = s.findRepeatedDnaSequences("AAGATCCGTCCCCCCAAGATCCGTC");

	for ( auto r : result ) {

			cout << r << endl;

	}

	return 0;
}
