// 12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <functional>

using namespace std;

class Solution {
public:
	string intToRoman(int num) 
	{
		std::string s("");

		std::map<int, std::string, std::greater<int>> ri 
		{
			std::make_pair(1000, "M"),
			std::make_pair(500, "D"),
			std::make_pair(100, "C"),
			std::make_pair(50, "L"),
			std::make_pair(10, "X"),
			std::make_pair(5, "V"),
			std::make_pair(1, "I")
		};
	
		int prevRV = 1000;
		std::string prevRN = "M";
		for (const auto &mi : ri) {
			//cout << mi.first << " " << mi.second.c_str() << endl;
			auto rv = mi.first;
			auto rn = mi.second;
			if (num == rv) {
				s += rn;
				break;
			} else if ((num > rv) && (num < prevRV) && (num >= (prevRV - 0.2*prevRV)) && (prevRN == "D" || prevRN == "L" || prevRN == "V")) {
				auto ps = (prevRN == "D") ? "CD" : (prevRN == "L") ? "XL" : (prevRN == "V") ? "IV" : "";
				s += ps;
				if (ps != "") {
					num -= 0.8 * prevRV;
				}

			} else if ( (num > rv) && (num < prevRV) && (num >= (prevRV - 0.1*prevRV)) ) {
				auto ps = (prevRN == "M") ? "CM" : (prevRN == "C") ? "XC" : (prevRN == "X") ? "IX" : "";
				s += ps;
				if (ps != "") {
					num -= 0.9 * prevRV;
				}
			} else if ( num > rv ) {
				auto q = num / rv;
				s += std::string(q, rn[0]);				
				num -= q*rv;
			}
			prevRV = mi.first;
			prevRN = mi.second;
			//cout << "s:" << s.c_str() << endl;
			//cout << "num:" << num << endl;
		}
	
		return s;
	}
};

int main()
{
	Solution s;
	cout << s.intToRoman(3999).c_str() << endl;
	cout << s.intToRoman(2500).c_str() << endl;
	cout << s.intToRoman(1846).c_str() << endl;
	cout << s.intToRoman(1123).c_str() << endl;
	cout << s.intToRoman(734).c_str() << endl;
	cout << s.intToRoman(271).c_str() << endl;
    return 0;
}

