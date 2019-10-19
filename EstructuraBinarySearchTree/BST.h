#pragma once
#include "NodeT.h"
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
	void printLevels();
	void destruye(NodeT* r);
	int  heightTree(NodeT* r);
	void printLeaves(NodeT *r);
	int countPreorden(NodeT *r);
	void inordenQueue(NodeT* r, queue<int> &q);
	NodeT* copyBST(NodeT* r);
	bool balanceado(NodeT* r);
	int diam(NodeT* r);

	//-----PARCIAL 2-----
	void meteStack(NodeT *r, stack<int> &s);

public:
	BST();
	~BST();
	bool search(int data);
	void add(int data);
	void remove(int data);
	void print(int tipo);
	int count();
	//TAREA 1
	int  height();
	vector<int> ancestors(int num);
	int whatLevelAmI(int num);

	//TAREA 2
	int maxWidth();
	int nearestRelative(int num1, int num2);
	BST(BST& otro);
	bool operator==(BST& otro);
	queue<int> toQueue();

	//TAREA 3
	int diameter();
	bool isBalanced();

	//-----PARCIAL 2-----
	int howManyAreSmallerThanME(int num);
	int oneChild();
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

/*
void BST::postordenPrint(NodeT* r) { //--------------------------------------------------------
	if (r != nullptr) {
		postordenPrint(r->getLeft());
		postordenPrint(r->getRight());
		if (r->getLeft() == nullptr && r->getRight() == nullptr) {
			cout << r->getData() << " ";
		}
	}
} */

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

//TAREA 1 - PRINT BY LEVELS
void BST::printLevels() {
	if (root == nullptr) { return; }
	queue<NodeT*> q;
	q.push(root);
	while (!q.empty()) {
		cout << q.front()->getData() << " ";
		if (q.front()->getLeft() != nullptr) {
			q.push(q.front()->getLeft());
		}
		if (q.front()->getRight() != nullptr) {
			q.push(q.front()->getRight());
		}
		q.pop();
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
	case 5: printLevels();
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

//TAREA 1 - HEIGHT
int BST::heightTree(NodeT *r) {
	if (r == nullptr) {
		return 0;
	}
	else {
		int left = heightTree(r->getLeft());
		int right = heightTree(r->getRight());
		return (left > right) ? left+1 : right+1;
	}
}

//TAREA 1 - HEIGHT
int BST::height() {
	return heightTree(root);
}

// TAREA 1 - ANCESTORS
vector<int> BST::ancestors(int num) {
	vector<int> ancestros;
	stack<int> myStack;
	NodeT* curr = root;
	bool found = false;
	while (curr != nullptr && !found) {
		if (curr->getData() == num) {
			found = true;
		}
		else {
			myStack.push(curr->getData());
			curr = (curr->getData() > num) ?
				curr->getLeft() : curr->getRight();
		}
	}

	if (found) {
		while (!myStack.empty()) {
			ancestros.push_back(myStack.top());
			myStack.pop();
		}
	}
	return ancestros;
}
//TAREA 1 - WHAT LEVEL AM I
int BST::whatLevelAmI(int num) {
	int level = 0;
	NodeT* curr = root;
	bool found = false;
	while (curr != nullptr && !found) {
		if (curr->getData() == num) {
			found = true;
		}
		else {
			level++;
			curr = (curr->getData() > num) ?
				curr->getLeft() : curr->getRight();
		}
	}
	return found ? level : -1;
}


//TAREA 2
void BST::inordenQueue(NodeT* r, queue<int> &q) {
	if (r != nullptr) {
		inordenQueue(r->getRight(), q);
		q.push(r->getData());
		inordenQueue(r->getLeft(), q);
	}
}

queue<int> BST::toQueue() {
	queue<int> q;
	inordenQueue(root, q);
	return q;
}

int BST::nearestRelative(int num1, int num2) {
	if (root->getData() == num1 || root->getData() == num2) {
		return NULL;
	}
	int nearest;
	NodeT* curr = root;
	while (curr->getData() != num1 && curr->getData() != num2) {
		nearest = curr->getData();
		if (num1 > curr->getData() && num2 > curr->getData()) {
			//SE QUE ME TENGO QUE MOVER A LA DERECHA
			if (curr->getRight()->getData() == num1 || curr->getRight()->getData() == num2) {
				return curr->getData();
			}
			else {
				curr = curr->getRight();
			}
		} else if ( (num1 > curr->getData() && num2 < curr->getData()) || (num1 < curr->getData() && num2 > curr->getData()) ) {
			//CURR ES EL NEAREST RELATIVE
			return curr->getData();
		}
		else if (num1 < curr->getData() && num2 < curr->getData()) {
			//SE QUE ME TENGO QUE MOVER A LA IZQUIERDA
			if (curr->getLeft()->getData() == num1 || curr->getLeft()->getData() == num2) {
				return curr->getData();
			}
			else {
				curr = curr->getLeft();
			}
		}
	}
}

NodeT* BST::copyBST(NodeT *r) {
	if (r == nullptr) {
		return nullptr;
	}
	else {
		NodeT* node = new NodeT(r->getData());
		node->setLeft(copyBST(r->getLeft()));
		node->setRight(copyBST(r->getRight()));
		return node;
	}
}

BST::BST(BST& otro) {
	root = copyBST(otro.root);
 }

bool BST::operator==(BST& otro) {
	queue<int> q1 = toQueue();
	queue<int> q2 = otro.toQueue();

	while (!q1.empty() && !q2.empty()) {
		if (q1.front() != q2.front())
			return false;
		q1.pop();
		q2.pop();
	}
	return true;
}

int BST::maxWidth() {
	if (root == nullptr) {
		return 0;
	}
	queue<NodeT*> q;
	q.push(root);
	int MaxW = 0, width;
	
	while (!q.empty()) {
		width = q.size();
		if (width > MaxW) {
			MaxW = width;
		}
		while (width > 0) {
			if (q.front()->getLeft() != nullptr) {
				q.push(q.front()->getLeft());
			}
			if (q.front()->getRight() != nullptr) {
				q.push(q.front()->getRight());
			}
			q.pop();
			width--;
		}
	}
	return MaxW;
}

int BST::diam(NodeT* r) {
	if (r == nullptr)
		return 0;
	int rootDiam = heightTree(r->getLeft()) + heightTree(r->getRight()) + 1;
	int ld = diam(r->getLeft());
	int rd = diam(r->getRight());
	return max(rootDiam, max(ld, rd));
}

int BST::diameter() {
	return diam(root);
}

bool BST::balanceado(NodeT* r) {
	if (r == nullptr) {
		return true;
	}
	int hLeft = heightTree(r->getLeft());
	int hRight = heightTree(r->getRight());
	if (hLeft-hRight == -1 || hLeft - hRight == 0 || hLeft - hRight == 1) {
		return true;
	}
	return false;
}

bool BST::isBalanced() {
	return balanceado(root);
}





//-----PARCIAL 2-----
void BST::meteStack(NodeT* r, stack<int>& s) {
	if (r != nullptr) {
		meteStack(r->getRight(), s);
		s.push(r->getData());
		meteStack(r->getLeft(), s);
	}
}

//howManyAreSmallerThanME
int BST::howManyAreSmallerThanME(int num) {
	if (root == nullptr)
		return 0;

	stack<int> myStack;
	meteStack(root, myStack);
	int count = 0;
	//TENGO STACK CON LOS NUMS ORDENADOR (MENOR HASTA ARRIBA)
	while (!myStack.empty()) {
		if (myStack.top() < num) {
			count++;
			myStack.pop();
		}
		else {
			return count;
		}
	}
	return count;
}

//oneChild
int BST::oneChild() {
	if (root == nullptr) {
		return 0;
	}
	queue<NodeT*> q;
	q.push(root);

	int count = 0;
	while (!q.empty()) {
		//SI TIENE UN SOLO HIJO
		if ( (q.front()->getLeft() == nullptr && q.front()->getRight() != nullptr) || (q.front()->getLeft() != nullptr && q.front()->getRight() == nullptr) ) {
			count++;
		}
		if (q.front()->getLeft() != nullptr) {
			q.push(q.front()->getLeft());
		}
		if (q.front()->getRight() != nullptr) {
			q.push(q.front()->getRight());
		}
		q.pop();
	}
	return count;
}