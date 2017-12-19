#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

typedef struct huffmanNode
{
	int fre;
	struct huffmanNode *left, *right;
}huffmanNode, *huffmanTree;
bool comp(huffmanNode h1, huffmanNode h2) {
	return h1.fre < h2.fre;
}
class Solution{
public:
	huffmanNode huffman(vector<int> &s) {
		vector<huffmanNode> sf;
		for (auto i = s.cbegin(); i != s.cend(); ++i) {
			huffmanTree temp = new huffmanNode;
			temp->fre = *i;
			temp->left = NULL;
			temp->right = NULL;
			sf.push_back(*temp);
		}
		while (sf.size()>1)
		{
			sort(sf.begin(), sf.end(), comp);
			huffmanTree temp = new huffmanNode;
			temp->fre = sf[0].fre + sf[1].fre;
			temp->left = &sf[0];
			temp->right = &sf[1];
			sf.erase(sf.begin(), sf.begin() + 2);
			sf.push_back(*temp);
		}
		return sf[0];
	}
	void PrintHuffman(huffmanNode *node, vector<int> vctchar)
	{
		if (node->left==node->right)
		{//���ߵ�Ҷ�ӽڵ㣬�������ӡvctchar�д�ı���
			cout << node->fre << ": ";
			for (vector<int>::iterator iter = vctchar.begin(); iter != vctchar.end(); iter++)
				cout << *iter;
			cout << endl;
			return;
		}
		else
		{
			vctchar.push_back(0);     //����������ʱ��vctchar�м�һ��1
			PrintHuffman(node->left, vctchar);
			vctchar.pop_back();       //���ݣ�ɾ���ոռӽ�ȥ��1
			vctchar.push_back(1);     //����������ʱ��vctchar�м�һ��0
			PrintHuffman(node->right, vctchar);
			vctchar.pop_back();       //���ݣ�ɾ���ոռӽ�ȥ��0
		}
	}
private:
	
};