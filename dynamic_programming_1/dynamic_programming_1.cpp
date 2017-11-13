#include "dynamic_programming_1.h"
#include <iomanip>

int main() {
	vector<int> v1, v2;
	Solution s;
	int p[] = {0,1,5,8,9,10,17,17,20,24,30};
	s.extendedBottomUpCutRod(v1, v2, p, size(p));
	for (int i=1;i<=10;++i)
		cout << left<<setw(3)<<v1[i]<<" ";
	cout << endl;
	for (int i = 1; i <= 10; ++i)
		cout << left << setw(3)<< v2[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}