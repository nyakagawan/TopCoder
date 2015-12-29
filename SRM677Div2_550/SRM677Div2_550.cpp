// SRM677Div2_550.cpp : Defines the entry point for the console application.
//

/*
Constraints
-
a will contain between 1 and 10 characters, inclusive.
-
b will contain between 1 and 10 characters, inclusive.
-
c will contain between 1 and 10 characters, inclusive.
-
d will contain between 1 and 10 characters, inclusive.
-
Each character in a will be a lowercase English letter ('a'-'z').
-
Each character in b will be a lowercase English letter ('a'-'z').
-
Each character in c will be a lowercase English letter ('a'-'z').
-
Each character in d will be a lowercase English letter ('a'-'z').

"abc"
"ab"
"bc"
"b"
Returns: 3
The shortest superstring in this test case is the string "abc". Note that each of the other three strings occurs in "abc" as a contiguous substring.
1)

    
"a"
"bc"
"def"
"ghij"
Returns: 10
In this case, one possible shortest superstring is "abcdefghij".
2)

    
"top"
"coder"
"opco"
"pcode"
Returns: 8
S = "topcoder"
3)

    
"thereare"
"arelots"
"lotsof"
"ofcases"
Returns: 19

4)

    
"aba"
"b"
"b"
"b"
Returns: 3

5)

    
"x"
"x"
"x"
"x"
Returns: 1
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class FourStrings {
public:
	int finSubStr(const char* src, const char* find, size_t srcLen, size_t findLen) {
		int matchPos = -1;
		for (int i = 0; i < srcLen; i++) {
			for (int j = 0; j < findLen; j++) {
				if ((i + j) >= srcLen) {
					break;
				}
				if (src[i + j] != find[j]) {
					matchPos = -1;
					break;
				}
				if (matchPos < 0) {
					matchPos = i + j;
				}
			}
			if (matchPos >= 0) {
				break;
			}
		}
		return matchPos;
	}

	int shortestLength(string a, string b, string c, string d)
	{
		string* strs[] = { &a, &b, &c, &d };

		std::vector<int> indices = { 0,1,2,3 };

#define BUFLEN 41
		int minLen = BUFLEN;
		char buf0[BUFLEN] = { 0 };
		char buf1[BUFLEN] = { 0 };
		char buf2[BUFLEN] = { 0 };
		char buf3[BUFLEN] = { 0 };
		do {
			int i = indices[0];
			sprintf(buf0, "%s", strs[i]->c_str());

			{
				int j = indices[1];
				memset(buf1, 0, BUFLEN);
				strcpy(buf1, buf0);

				int subPos = finSubStr(buf1, strs[j]->c_str(), strlen(buf1), strs[j]->length());
				if (subPos >= 0) {
					for (int iS = 1; iS < strs[j]->length(); iS++) {
						buf1[subPos + iS] = *(strs[j]->c_str() + iS);
					}
				}
				else {
					strcat(buf1, strs[j]->c_str());
				}

				{
					int k = indices[2];
					memset(buf2, 0, BUFLEN);
					strcpy(buf2, buf1);

					int subPos2 = finSubStr(buf2, strs[k]->c_str(), strlen(buf2), strs[k]->length());
					if (subPos2 >= 0) {
						for (int iS = 1; iS < strs[k]->length(); iS++) {
							buf2[subPos2 + iS] = *(strs[k]->c_str() + iS);
						}
					}
					else {
						strcat(buf2, strs[k]->c_str());
					}

					{
						int l = indices[3];
						memset(buf3, 0, BUFLEN);
						strcpy(buf3, buf2);

						int subPos3 = finSubStr(buf3, strs[l]->c_str(), strlen(buf3), strs[l]->length());
						if (subPos3 >= 0) {
							for (int iS = 1; iS < strs[l]->length(); iS++) {
								buf3[subPos3 + iS] = *(strs[l]->c_str() + iS);
							}
						}
						else {
							strcat(buf3, strs[l]->c_str());
						}

						int len = strlen(buf3);
						if (len < minLen) {
							minLen = len;
						}
					}
				}
			}
		} while (next_permutation(indices.begin(), indices.end()));

		return minLen;
	}
};

int main()
{
	//"abc" "de", "cd", "ef"
	//"abc" "cef", "chk", "ef"
	FourStrings ins;
	cout << ins.shortestLength("abc", "ab", "bc", "b") << endl;//Returns: 3
	cout << ins.shortestLength("a", "bc", "def", "ghij") << endl;//Returns: 10
	cout << ins.shortestLength("top", "coder", "opco", "pcode") << endl;//Returns: 8
	cout << ins.shortestLength("thereare", "arelots", "lotsof", "ofcases") << endl;//Returns: 19
	cout << ins.shortestLength("aba", "b", "b", "b") << endl;//Returns: 3
	cout << ins.shortestLength("x", "x", "x", "x") << endl;//Returns: 1
	return 0;
}

