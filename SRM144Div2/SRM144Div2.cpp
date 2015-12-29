// SRM144Div2.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//


//#include "stdafx.h"
//#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Time {
public: 
	string whatTime(int seconds) 
	{
		int h = seconds / 3600;
		int m = (seconds - (h * 3600)) / 60;
		int s = (seconds - (h * 3600) - (m * 60));
		char buf[256];
		sprintf(buf, "%d:%d:%d", h, m, s);
		return string(buf);
	}
};

int main()
{
	Time time;

	cout << time.whatTime(0).c_str() << endl;//Returns: "0:0:0"
	cout << time.whatTime(3661).c_str() << endl;//Returns: "1:1:1"
	cout << time.whatTime(5436).c_str() << endl;//Returns: "1:30:36"
	cout << time.whatTime(86399).c_str() << endl;//"23:59:59"

    return 0;
}

