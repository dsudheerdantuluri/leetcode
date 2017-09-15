#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) 
		{
			auto cmp = [](int i, int j) {
				string istr(to_string(i));
				string jstr(to_string(j));

				string ij(istr + jstr), ji(jstr + istr);
				return stoi(ij) > stoi(ji);
     	};

			sort(nums.begin(), nums.end(), cmp);	
  
			string result("");
	
			for ( auto n : nums ) result += to_string(n);

			if ( all_of(result.begin(), result.end(), [](char c) { return c == '0'; }) ) {
				return "0";
			}

			return result; 
    }
};

int main()
{
	Solution s;
	vector<int> v({0, 0});
	cout << s.largestNumber(v) << endl;
	return 0;
}
