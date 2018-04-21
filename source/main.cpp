#include<iostream>
#include "opencv.h"
#include<string>
#include <cstdio>
#include <cstdlib>
#include<vector>
#include"CubicExplorer.h"
#include"cstring"
extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "solve.h"
}

int main() {
	Capture("Case1");
	//一只手张开一只手松开
	//Capture("Case2");
	string cubicState;
	cubicState = Recognition();
	char* cp = new char[cubicState.length() + 1];
	strcpy(cp, cubicState.c_str());
	char* res = solve(cp, NULL);

	CubicExplorer explorerInstance(res);		//构造解算器的实例

	if (res == nullptr) {
		cout << "Unsolved Cubic" << endl;
	}
	else {
		puts(res);
		explorerInstance.GetShortestWay();
		explorerInstance.ShowOperations();
	}

	free(res);
	return 0;

}