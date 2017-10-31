#include<iostream>
#include<iomanip>

typedef struct BitreeNode
{
	char data;
	BitreeNode *lchild, *rchild;
}*Bitree;
using namespace std;

void createBitree(Bitree &t);
void travelBitree(Bitree t);

int main() {
	Bitree bt;
	createBitree(bt);
	travelBitree(bt);
	system("pause");
	return 0;
}

void createBitree(Bitree &t) {
	char ch;
	cin >> ch;
	if (ch == '/') {
		t = NULL;
	}
	else
	{
		t = new BitreeNode();
		t->data = ch;
		createBitree(t->lchild);
		createBitree(t->rchild);
	}
}

void travelBitree(Bitree t) {
	if (t) {
		cout << t->data << " ";
		if(t->lchild)
			travelBitree(t->lchild);
		if(t->rchild)
			travelBitree(t->rchild);
	}
}