#include <iostream>
#include "BSTree.h"

using namespace std;

int main() {
	BSTree<int> b;
	b.insert(4);
	b.insert(1);
	b.insert(2);
	b.insert(8);
	b.insert(5);
	b.insert(6);
	b.insert(9);
	b.printTree(cout);
	cout << endl;
	b.remove(2);
	b.printTree(cout);
	system("pause");
	return 0;
}