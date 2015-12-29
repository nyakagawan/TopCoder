// SRM672Div2_500.cpp : Defines the entry point for the console application.
//

/*
Constraints
-
a will contain between 1 and 50 characters, inclusive.
-
a and b will contain the same number of characters.
-
It is guaranteed that b can be obtained from a by applying some substitution cipher.
-
y will contain between 1 and 50 characters, inclusive.
-
Each character in a, b, and y will be an uppercase English letter ('A'-'Z').
Examples
0)

    
"CAT"
"DOG"
"GOD"
Returns: "TAC"
By observing a and b we see that each C is encoded as a D, each A is encoded as an O, and each T is encoded as a G. Formally, we have p(C)=D, p(A)=O, and p(T)=G. This information is sufficient to determine that the encrypted string "GOD" must have been created from the plaintext string "TAC".
1)

	    
"BANANA"
"METETE"
"TEMP"
Returns: ""
We do not know which character was encoded as the letter P. Thus, there are multiple possiblities for the string x. For example, x can be "NABC" or "NABD".
2)

		    
"THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG"
"UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH"
"DIDYOUNOTICESKIPPEDLETTER"
Returns: "CHCXNTMNSHBDRJHOODCKDSSDQ"
This test case is tricky. Note that the letter E does occur in y but it does not occur in b. However, in this specific case we can still determine that the letter E must be decrypted to a D.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

class SubstitutionCipher {
public:
	string decode(string a, string b, string y) {
		char subTable[26] = {0};//index 0 is 'A' 25 is 'Z'

		int fillCount = 0;
		int fillBits = 0;
		for (int i = 0; i < a.length(); i++) {
			unsigned char index = b[i] - 'A';
			if (subTable[index] == '\0') {
				fillBits |= 1 << (a[i] - 'A');
				fillCount++;
				subTable[index] = (char)a[i];
			}
		}

		char ans[51] = {0};
		for (int i = 0; i < y.length(); i++){
			auto iy = y[i] - 'A';
			if (subTable[(unsigned char)iy] == '\0') {
				if (fillCount == 25) {
					for (int bit = 0; bit < 26; bit++) {
						if ((fillBits & (1 << bit)) == 0) {
							subTable[(unsigned char)iy] = 'A' + bit;
							goto NEXTLOOP;
						}
					}
				}
				return "";
			}
		NEXTLOOP:
			ans[i] = subTable[(unsigned char)iy];
		}

		return string(ans);
	}
};

int main()
{
	SubstitutionCipher cls;
	{
		string a = "CAT";
		string b = "DOG";
		string y = "GOD";
		cout << cls.decode(a, b, y).c_str() << endl;//"TAC"
	}
	{
		auto a = "BANANA";
		auto b = "METETE";
		auto y = "TEMP";
		cout << cls.decode(a, b, y) << endl;//""
	}
	{
		auto a = "THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG";
		auto b = "UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH";
		auto y = "DIDYOUNOTICESKIPPEDLETTER";
		cout << cls.decode(a, b, y) << endl;//"CHCXNTMNSHBDRJHOODCKDSSDQ"
	}
	return 0;
}

