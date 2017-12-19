#include "Huffman.h"

int main() {
	Solution s;
	vector<int> v = { 45,13,12,16,9,5 };
	huffmanNode h = s.huffman(v);
	vector<int> vctchar;
	s.PrintHuffman(&h, vctchar);
	cin.get();
	return 0;
}