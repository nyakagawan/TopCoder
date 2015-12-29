// SRM672Div2_250.cpp : Defines the entry point for the console application.
//

/*
Constraints
-
Each of arrays a and b will have length between 1 and 50, inclusive.
-
Each element of arrays a and b will be between 1 and 100, inclusive.
-
In each of arrays a and b all elements are distinct.
Examples
0)

    
{1, 2, 3, 5, 8}
{8, 5, 1, 3, 2}
Returns: "EQUAL"
The order of elements in a and b does not matter. The two sets X and Y are equal.
1)

	    
{2, 3, 5, 7}
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
Returns: "LESS"
Each number that occurs in a does also occur in b.
2)

		    
{2, 4, 6, 8, 10, 12, 14, 16}
{2, 4, 8, 16}
Returns: "GREATER"

3)

			    
{42, 23, 17}
{15, 23, 31}
Returns: "INCOMPARABLE"
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class SetPartialOrder {
public:
	string compareSets(vector <int> a, vector <int> b) {
		int sameCount = 0;
		for (auto i : a) {
			for (auto k : b)
			{
				if (i == k) {
					sameCount++;
				}
			}
		}

		int aLen = a.size();
		int bLen = b.size();
		int lenDiff = aLen - bLen;

		if (lenDiff == 0) {
			if (sameCount == aLen) {
				return "EQUAL";
			}
		}
		else if (lenDiff < 0) {
			if (sameCount == aLen) {
				return "LESS";
			}
		}
		else if (lenDiff > 0) {
			if (sameCount == bLen) {
				return "GREATER";
			}
		}

		return "INCOMPARABLE";

	}
};


int main()
{
	SetPartialOrder cls;
	{
		//EQUAL
		auto a = { 1, 2, 3, 5, 8 };
		auto b = { 8, 5, 1, 3, 2 };
		cout << cls.compareSets(a, b) << endl;
	}
	{
		//LESS
		auto a = { 2, 3, 5, 7 };
		auto b = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		cout << cls.compareSets(a, b) << endl;

	}
	{
		//GREATER
		auto a = { 2, 4, 6, 8, 10, 12, 14, 16 };
		auto b = { 2, 4, 8, 16 };
		cout << cls.compareSets(a, b) << endl;
	}
	{
		//INCOMPARABLE
		auto a = { 42, 23, 17 };
		auto b = { 15, 23, 31 };
		cout << cls.compareSets(a, b) << endl;
	}
	return 0;
}

