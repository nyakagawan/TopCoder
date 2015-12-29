// SRM677Div2_250.cpp : Defines the entry point for the console application.
//

/*
The number 1 is not a prime number.
Constraints
-
L will be between 1 and 1,000, inclusive.
-
R will be between L and 1,000, inclusive.

*/

#include <iostream>
#include <cmath>

using namespace std;

class PalindromePrime {
public:
	bool isPrime(int num) {
		int checkMax = (int)sqrt((double)num);
		for (int i = 3; i <= checkMax; i += 2) {
			if ((num % i) == 0) {
				return false;
			}
		}
		return true;
	}

	int count(int L, int R) {
		int ret = 0;
		//char buf[64];

		int digit = 1;
		int work = 10;
		while (true) {
			if ((L - work) < 0) {
				break;
			}
			digit++;
			work *= 10;
		}
		//printf("digit %d\n", digit);

		int workArray[32] = { 0 };

		for (int i = L; i <= R; i++) {
			if ((i - work) >= 0) {
				digit++;
				//printf("digit %d\n", digit);
				work *= 10;
			}

			if (i < 2) {
				continue;
			}
			if (i == 2) {
				ret++;
				continue;
			}
			if ((i % 2) == 0) {
				continue;
			}

			if (isPrime(i)) {
				//cout << "prime:" << i << endl;
				if (digit == 1) {
					ret++;
					continue;
				}

				int tmp = i;
				for (int j = 0; j < digit; j++) {
					workArray[j] = tmp % 10;
					tmp /= 10;
				}

				bool palindrome = true;
				for (int j = 0; j < (digit / 2); j++) {
					if (workArray[j] != workArray[digit - j - 1]) {
						palindrome = false;
						break;
					}
				}

				if (palindrome) {
					//cout << "prime:" << i << endl;
					ret++;
				}
			}
		}
		return ret;
	}
};

int main()
{
	PalindromePrime palindrome;
	cout << palindrome.count(100, 150) << endl;//return 2
	cout << palindrome.count(1, 9) << endl;//return 4
	cout << palindrome.count(929, 929) << endl;//return 1
	cout << palindrome.count(1, 1) << endl;//return 0
	cout << palindrome.count(1, 1000) << endl;//return 20
	return 0;
}

