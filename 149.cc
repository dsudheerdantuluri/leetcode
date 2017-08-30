#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
private:
		int gcd(int a, int b)
		{
			if (b==0) return a;
			return gcd(b, a%b);
		}

public:
    int maxPoints(vector<Point>& points) 
		{
			if (points.size() <= 2) return points.size();

			int highest = 0;

			for (int i = 0; i < points.size(); ++i) {

				int localMax = 0, vertical = 0, overlap = 0, sameSlope = 0;
	
				map<pair<int, int>, int> hash;

				for (int j = 0; j < points.size(); ++j) {

					if ( (points[i].x == points[j].x) &&
							 (points[i].y == points[j].y) ) {
						overlap++;
					} else if ( points[i].x == points[j].x ) {
						vertical++;
					}	else {
						auto num = points[j].y - points[i].y;			
						auto denom = points[j].x - points[i].x;
						auto g = gcd(num, denom);
						num /= g;
						denom /= g;
						sameSlope = max(sameSlope, ++hash[make_pair(num, denom)]);
					}
					localMax = overlap + max(vertical, sameSlope);
				}

				highest = max(highest, localMax);
			}

			return highest;
    }
};

int main()
{
	return 0;
}
