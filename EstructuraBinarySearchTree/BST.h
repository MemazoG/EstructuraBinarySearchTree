#pragma once
#include "NodeT.h"
#include <iostream>
using namespace std;

class BST {
private:
	NodeT* root;
	int howManyChildren(NodeT* r);
	int succ(NodeT* r);
	int pred(NodeT* r);
	void preorden(NodeT* root);
	void inorden(NodeT* r);
	void postorden(NodeT* r);
	void destruye(NodeT* r);

	void printLeaves(NodeT *r);
	int countPreorden(NodeT *r);

public:
	BST();
	~BST();
	bool search(int data);
	void add(int data);
	void remove(int data);
	void print(int tipo);
	int count();
};

BST::BST() {
	root = nullptr;
}

BST::~BST() {
	destruye(root);
}

int BST::howManyChildren(NodeT* r) {
	int cont = 0;
	if (r->getLeft() != nullptr) {
		cont++;
	}
	if (r->getRight() != nullptr) {
		cont++;
	}
	return cont;
}

int BST::succ(NodeT* r) {
	NodeT* curr = r->getRight();
	while (curr->getLeft() != nullptr) {
		curr = curr->getLeft();
	}
	return curr->getData();
}

int BST::pred(NodeT* r) {
	NodeT* curr = r->getLeft();
	while (curr->getRight() != nullptr) {
		curr = curr->getRight();
	}
	return curr->getData();
}

bool BST::search(int data) {
	NodeT* curr = root;
	while (curr != nullptr) {
		if (curr->getData() == data) {
			return true;
		}
		curr = (curr->getData() > data) ?
			curr->getLeft() : curr->getRight();
	}
	return false;
}

void BST::add(int data) {
	NodeT* curr = root;
	NodeT* father = nullptr;

	while (curr != nullptr && curr->getData() != data) {
		father = curr;
		curr = (curr->getData() > data) ?
			curr->getLeft() : curr->getRight();
	}
	//Si el dato ya está en el árbol
	if (curr != nullptr) {
		return;
	}
	//Si el árbol está vacío
	if (father == nullptr) {
		root = new NodeT(data);
	}
	else if (father->getData() > data) {
		father->setLeft(new NodeT(data));
	}
	else {
		father->setRight(new NodeT(data));
	}
}

void BST::remove(int data) {
	NodeT* curr = root;
	NodeT* father = nullptr;

	while (curr != nullptr && curr->getData() != data) {
		father = curr;
		curr = (curr->getData() > data) ?
			curr->getLeft() : curr->getRight();
	}

	//Si no está el dato
	if (curr == nullptr) {
		return;
	}
	int cantHijos = howManyChildren(curr);
	switch (cantHijos) {
	case 0: {
		if (father == nullptr) {
			root = nullptr;
		}
		else {
			if (father->getData() > data) {
				father->setLeft(nullptr);
			}
			else {
				father->setRight(nullptr);
			}
		}
		delete curr;
		break;
	}
	case 1: {
		if (father == nullptr) {
			if (curr->getLeft() != nullptr) {
				root = curr->getLeft();
			}
			else {
				root = curr->getRight();
			}
		}
		else {
			if (father->getData() > data) {
				if (curr->getLeft() != nullptr) {
					father->setLeft(curr->getLeft());
				}
				else {
					father->setLeft(curr->getRight());
				}
			}
			else {
				if (curr->getLeft() != nullptr) {
					father->setRight(curr->getLeft());
				}
				else {
					father->setRight(curr->getRight());
				}
			}
		}
		delete curr;
		break;
	}
	case 2: {
		int dataSucesor = succ(curr);
		remove(dataSucesor);
		curr->setData(dataSucesor);
		delete curr;
		break;
	}
	}
}

void BST::postordenPrint(NodeT* r) { //--------------------------------------------------------
	if (r != nullptr) {
		postordenPrint(r->getLeft());
		postordenPrint(r->getRight());
		if (r->getLeft() == nullptr && r->getRight() == nullptr) {
			cout << r->getData() << " ";
		}
	}
}

void BST::preorden(NodeT* r) {
	if (r != nullptr) {
		cout << r->getData() << " ";
		preorden(r->getLeft());
		preorden(r->getRight());
	}
}

void BST::inorden(NodeT* r) {
	if (r != nullptr) {
		inorden(r->getLeft());
		cout << r->getData() << " ";
		inorden(r->getRight());
	}
}

void BST::postorden(NodeT* r) {
	if (r != nullptr) {
		postorden(r->getLeft());
		postorden(r->getRight());
		cout << r->getData() << " ";
	}
}

void BST::destruye(NodeT* r) {
	if (r != nullptr) {
		destruye(r->getLeft());
		destruye(r->getRight());
		delete r;
	}
}

void BST::printLeaves(NodeT* r) {
	if (r != nullptr) {
		if (r->getLeft() == nullptr && r->getRight() == nullptr) {
			cout << r->getData() << " ";
		}
		else {
			printLeaves(r->getLeft());
			printLeaves(r->getRight());
		}
	}
}

void BST::print(int tipo) {
	switch (tipo) {
	case 1: preorden(root);
			break;
	case 2: inorden(root);
			break;
	case 3: postorden(root);
			break;
	case 4: printLeaves(root);
			break;
	}
}

int BST::countPreorden(NodeT* r) {
	if (r == nullptr) {
		return 0;
	}
	return 1 + countPreorden(r->getLeft()) + countPreorden(r->getRight());
}

int BST::count() {
	return countPreorden(root);
}

/* void BST::printLeaves() {
	postordenPrint(root);
} */

/* int BST::numNodos(NodeT* r, int &suma) {
	if (r != nullptr) {
		numNodos(r->getLeft(), suma);
		numNodos(r->getRight(), suma);
		suma++;

	}
} */
