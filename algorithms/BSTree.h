#pragma once

#include<iostream>

using namespace std;


template<typename T>
class BSTree{
public:
	BSTree():m_root(nullptr) {}
	BSTree(const BSTree &rhs) { m_root = clone(rhs.m_root); }
	~BSTree() { makeEmpty(); }
	const T findMin() const { return findMin(m_root)->element; }
	const T findMax() const { return findMax(m_root)->element; }
	bool contain(const T &x) { return contain(x, m_root); }
	bool isEmpty()const { return m_root==nullptr; }
	void printTree(ostream &out=cout) const { 
		if (isEmpty())
			out << "empty tree!\n";
		else
			printTree(m_root,out); 
	}
	void makeEmpty() { makeEmpty(m_root); }
	void insert(const T &x) { insert(x, m_root); }
	void remove(const T &x) { remove(x, m_root); }
	const BSTree& operator=(BSTree &rhs) {
		if (this != rhs) {
			BSTreeNode *tmp = clone(rhs.m_root);
			makeEmpty();
			m_root = tmp;
		}
		return *this;
	}
private:
	struct BSTreeNode
	{
		T element;
		BSTreeNode *lchild;
		BSTreeNode *rchild;
		BSTreeNode(const T &theElement,
			BSTreeNode *lt,
			BSTreeNode *rt)
			: element(theElement), lchild(lt), rchild(rt) {}
	};
	BSTreeNode *m_root;
	BSTreeNode* findMin(BSTreeNode *t) {
		if (t == nullptr)
			return nullptr;
		while (t->lchild)
		{
			t = t->lchild;
		}
		return t;
	}
	BSTreeNode* findMax(BSTreeNode *t) {
		if (t == nullptr)
			return nullptr;
		if (!t->rchild)
			return t;
		return findMax(t->rchild);
	}
	void insert(const T &x, BSTreeNode *&t) {
		if (!t)
			t = new BSTreeNode(x, nullptr, nullptr);
		else if (x > t->element)
			insert(x, t->rchild);
		else if (x < t->element)
			insert(x, t->lchild);
	}
	void remove(const T &x, BSTreeNode *&t) {
		if (t == nullptr)
			return;
		if (x > t->element)
			remove(x, t->rchild);
		else if (x < t->element)
			remove(x, t->lchild);
		else if (t->lchild != nullptr&&t->rchild != nullptr) {
			t->element = findMin(t->rchild)->element;
			remove(t->element, t->rchild);
		}
		else {
			BSTreeNode *oldNode = t;
			t = t->lchild != nullptr ? t->lchild : t->rchild;
			delete oldNode;
		}
	}
	bool contain(const T &x, BSTreeNode *t) {
		if (!t)
			return false;
		if (x > t->element)
			return contain(x, t->rchild);
		else if (x < t->element)
			return contain(x, t->lchild);
		else
			return true;
	}
	void makeEmpty(BSTreeNode *t) {
		if (!t)
			return;
		else
		{
			if (t->lchild)
				makeEmpty(t->lchild);
			if (t->rchild)
				makeEmpty(t->rchild);
			delete t;
		}
		t = nullptr;
	}
	void printTree(BSTreeNode *t,ostream &out) const {
		if (!t)
			return;
		else {
			printTree(t->lchild,out);
			out << t->element << " ";
			printTree(t->rchild,out);
		}
	}
	BSTreeNode *clone(BSTreeNode *t) {
		if (!t)
			return nullptr;
		else
		{
			return new BSTreeNode(t->element, clone(t->lchild), clone(t->rchild));
		}
	}
};
