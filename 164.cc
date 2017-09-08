#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {

  class Bucket {
    public:
      bool used = false;
      int minVal = numeric_limits<int>::max();
      int maxVal = numeric_limits<int>::min();
  };  

  public:
    int maximumGap(vector<int>& nums) 
    {   
      if (nums.size() < 2) return 0;

      int size = nums.size();

      int minVal = *min_element(nums.begin(), nums.end());

      int maxVal = *max_element(nums.begin(), nums.end());

			cout << "minVal:" << minVal << endl;

			cout << "maxVal:" << maxVal << endl;
  
      int smallestMaxDiff = max(1, (maxVal - minVal) / (size - 1));

      int numBuckets = ((maxVal - minVal) / smallestMaxDiff); 

			cout << "smallestMaxDiff:" << smallestMaxDiff << endl;

			cout << "numBuckets:" << numBuckets << endl;

      vector<Bucket> buckets(numBuckets + 1);

      for (auto n : nums) {

        int bi = (n - minVal)/ smallestMaxDiff; 

				//cout << "bi:" << bi << endl;
				
				//cout << "used:" << buckets[bi].used << endl;
				
				//cout << "minVal:" << buckets[bi].minVal << endl;

				//cout << "maxVal:" << buckets[bi].maxVal << endl;

        buckets[bi].used = true;
				
        buckets[bi].minVal = min(n, buckets[bi].used ? buckets[bi].minVal : n);
  
        buckets[bi].maxVal = max(n, buckets[bi].used ? buckets[bi].maxVal : n);  
			
				//cout << "used:" << buckets[bi].used << endl;

				//cout << "minVal:" << buckets[bi].minVal << endl;

				//cout << "maxVal:" << buckets[bi].maxVal << endl;
        
      }  

			//cout << "fine till here " << endl; 

      int maxDiff = 0;
        
      int prevBucketMaxVal = minVal;

      for ( int i = 0; i < buckets.size(); ++i ) { 

        if (!buckets[i].used) continue;

        maxDiff = max(maxDiff, buckets[i].minVal - prevBucketMaxVal);
          
        prevBucketMaxVal = buckets[i].maxVal;

      }   

      return maxDiff;   

    }   
};


int main()
{
	Solution s;
	vector<int> nums{1,3, 100};
	cout << s.maximumGap(nums) << endl;
	return 0;
}

