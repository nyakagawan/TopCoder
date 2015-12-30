// SRM672Div2_1000.cpp : Defines the entry point for the console application.
//

/*
Constraints
-
s will contain n elements.
-
n will be between 2 and 18, inclusive.
-
Each element in s will contain exactly n characters.
-
Each character in s will be between '0' and '9', inclusive.
-
s will be symmetric, so s[i][j] will be equal to s[j][i].
-
Diagonal characters are not significant, so s[i][i] will be equal to '0'.
Examples
0)

    
{"000","000","000"}
Returns: 3
Nobody knows anything about anybody else.
If the killer is person 1, the smallest number of rounds is ans[1]=1: after the initial interview of person 0 there will be a single round in which the detective interviews person 1.
If the killer is person 2, the smallest number of rounds is again ans[1]=1: after interviewing person 0 both other people have the same suspicion level, so the detective can also choose person 2 in the first round.
The correct return value is 1*1 + 2*1 = 3.
1)

	    
{"0224","2011","2104","4140"}
Returns: 10
After the initial interview the detective will always choose person 3 in the first round. If person 3 is not the killer, the detective will receive new information that will increase the suspicion level of person 2. Therefore, in the second round the detective will interview person 2. If person 2 is also not the killer, there will be a third round in which the detective interviews the last remaining person: person 1.
Hence, the answers are ans[1]=3, ans[2]=2, and ans[3]=1. Therefore, the correct return value is 1*3 + 2*2 + 3*1 = 10.
2)

		    
{"0886","8086","8801","6610"}
Returns: 12

3)

			    
{"064675511","603525154","430262731","652030511","726302420","552020464","517544052","153126500","141104200"}
Returns: 170

4)

				    
{"0313131","3030020","1301132","3010031","1010003","3233003","1021330"}
Returns: 37

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <assert.h>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

class Tdetectived2 {
public:
	const int kPrioMax = 9;
	u8* ppSuspision;
	u8 N;

	vector<int> shotestRoundMap;

	void sub(u8* pDone, u8* pPriority, int round) {
		round++;

		vector<int> vecHighestPrioIndex;
		int highestPrio = -1;
		for (int i = 1; i < N; i++) {
			if (pDone[i]) {
				continue;
			}
			if (pPriority[i] >= highestPrio) {
				if (pPriority[i] > highestPrio) {
					vecHighestPrioIndex.clear();
				}
				highestPrio = pPriority[i];
				vecHighestPrioIndex.push_back(i);
			}
		}

		if (vecHighestPrioIndex.size() == 0)
			return;

		for (auto hpi : vecHighestPrioIndex) {
			if (shotestRoundMap[hpi] > round) {
				shotestRoundMap[hpi] = round;
			}
		}

		vector<u8> vecPrio((size_t)N);
		for (auto hpi : vecHighestPrioIndex) {
			pDone[hpi] = 1;

			for (int i = 1; i < N; i++) {
				vecPrio[i] = max<u8>(pPriority[i], ppSuspision[hpi * N + i]);
			}
			sub(pDone, vecPrio.data(), round);

			pDone[hpi] = 0;
		}
	}

	int reveal(vector <string> S) {
		auto sSize = S.size();
		N = (u8)S[0].length();
		ppSuspision = new u8[sSize * N];
		memset(ppSuspision, 0, sSize * N);
		for (int i = 0; i < N; i++) {
			for (auto j = 0; j < N; j++) {
				char c = S[i][j];
				ppSuspision[i * N + j] = (u8)(c - '0');
			}
		}

		shotestRoundMap = vector<int>(N);
		fill(shotestRoundMap.begin(), shotestRoundMap.end(), INT_MAX);

		u8* pDone = new u8[N];
		u8* pPrio = new u8[N];

		memset(pDone, 0, N);
		memcpy(pPrio, &ppSuspision[0], N);
		sub(pDone, pPrio, 0);

		int ans = 0;
		for (int i = 1; i < N; i++) {
			ans += shotestRoundMap[i] * i;
		}

		delete[] ppSuspision;
		delete[] pDone;
		delete[] pPrio;

		return ans;
	}
};

static chrono::time_point<chrono::system_clock> sStartTime;
void TimerStart() {
	sStartTime = chrono::system_clock::now();
}
void PrintTime() {
	const auto timeSpan = chrono::system_clock::now() - sStartTime;
	cout << "Time: " << chrono::duration_cast<chrono::microseconds>(timeSpan).count() << "[micro sec]" << endl;
}

int main()
{
	Tdetectived2 cls;
	TimerStart();
	//3
	cout << cls.reveal({ "000","000","000" }) << endl;
	//10
	cout << cls.reveal({ "0224","2011","2104","4140" }) << endl;
	//12
	cout << cls.reveal({ "0886","8086","8801","6610" }) << endl;
	//170
	cout << cls.reveal({ "064675511","603525154","430262731","652030511","726302420","552020464","517544052","153126500","141104200" }) << endl;
	//37
	cout << cls.reveal({ "0313131","3030020","1301132","3010031","1010003","3233003","1021330" }) << endl;
	PrintTime();
	return 0;
}

