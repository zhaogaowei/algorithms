#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	void extendedBottomUpCutRod(vector<int> &v1,vector<int> &v2,int *p,int n) {
		v1.resize(n + 1);
		v2.resize(n + 1);
		v1[0] = 0;
		v2[0] = 0;
		for (auto j = 1; j <= n; ++j) {
			int q = 0;
			for (auto i = 1; i <= j; i++) {
				if (q < p[i] + v1[j - i]) {
					q = p[i] + v1[j - i];
					v2[j] = i;
				}
			}
			v1[j] = q;
		}
	}
private:

};