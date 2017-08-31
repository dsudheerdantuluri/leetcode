#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
		{
			vector<int> result;
			
			int i = 0, j = numbers.size()-1;

			while ( i < j ) {
				int sum = numbers[i] + numbers[j];
				if ( sum == target ) {
					result.emplace_back(i+1);
					result.emplace_back(j+1);
					return result;
				} else if ( sum > target ) --j;
				else ++i;
			}
       
			return result; 
    }
};

int main()
{

	return 0;
}
