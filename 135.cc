#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

auto printScalar = [](int i) { cout << " " << i; };

void printVector(vector<int> &vec)
{
	for_each(vec.begin(), vec.end(), printScalar);
	cout << endl;
}

struct Sum
{
	Sum() : sum{0} {}; 
  void operator()(int i) { sum += i; }
	int sum;
};

class Solution 
{
	public:
		bool hasHigherRatingThanNbour(vector<int> &ratings, int i)
		{
			int n = ratings.size();

			if ( i < 1 ) {
				return ratings[i] > ratings[i+1];	
			} else if ( i >= n-1 ) {
				return ratings[i] > ratings[i-1];
			} else {
				return ( (ratings[i] > ratings[i+1]) ||
				         (ratings[i] > ratings[i-1]) ); 

			} 
		}

		int highestCandiesOfNbour(vector<int> &candies, vector<int> &ratings, int i)
		{
			int n = candies.size();

			if ( i < 1 ) {
				return candies[i+1];
			} else if ( i >= n-1 ) {
				return candies[i-1];
			} else {
				if ( (ratings[i] > ratings[i+1]) &&
						 (ratings[i] > ratings[i-1]) ) {
					return max(candies[i-1], candies[i+1]);
				} else if (ratings[i] > ratings[i-1]) {
					return candies[i-1];
				} else {
					return candies[i+1];
				}
			}
		}

    int candy(vector<int>& ratings) {

			vector<int> sortedChildren(ratings.size());

			for (int i=0; i < sortedChildren.size(); ++i) {
				sortedChildren[i] = i;
			}

			auto cmp = [&ratings](int i, int j) { return ratings[i] < ratings[j]; };

			sort(sortedChildren.begin(), sortedChildren.end(), cmp);
			//printVector(sortedChildren);

			vector<int> candies(ratings.size(), 1);
			//printVector(candies);

			for (int i = 1; i < sortedChildren.size(); ++i) {
				if (hasHigherRatingThanNbour(ratings, sortedChildren[i]))
					candies[sortedChildren[i]] = highestCandiesOfNbour(candies, ratings, sortedChildren[i]) + 1;
			}
			//printVector(candies);

			Sum s = for_each(candies.begin(), candies.end(), Sum());

			return s.sum;
    }
};

int main()
{
	//vector<int> ratings{2,3,1,4};
	//vector<int> ratings{2,1};
	//vector<int> ratings{1,2,2};
	vector<int> ratings{1,2,4,4,3};

	Solution s;
	cout << s.candy(ratings) << endl;

	return 0;
}
