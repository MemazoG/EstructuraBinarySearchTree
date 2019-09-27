#pragma once
#include "NodeT.h"

class BST {
private:
	NodeT* root;

public:
	BST();
	~BST();
	bool search(int data);
	void add(int data);
	void remove(int data);
	void print(int tipo);
	//1 - Imprime en preorden
	//2 - Imprime en inorden
	//3 - Imprime en postorden
};

BST::BST() {
	root = nullptr;
}

BST::~BST() {

}