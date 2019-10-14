// EstructuraBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "BST.h"
#include <iostream>
using namespace std;

int main()
{
	BST miArbol;
	miArbol.add(14);
	miArbol.add(10);
	miArbol.add(20);
	miArbol.add(5);
	miArbol.add(7);
	miArbol.add(12);
	miArbol.add(18);
	miArbol.add(25);
	miArbol.add(23);
	miArbol.add(22);
	miArbol.add(26);

	//PRUEBA toQueue()
	cout << "*****PRUEBA toQueue()*****" << endl;
	queue<int> q = miArbol.toQueue();
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

	//PRUEBA nearestRelative(x, y)
	cout << "*****PRUEBA nearestRelative(22, 25)" << endl;
	cout << miArbol.nearestRelative(22, 25) << endl;

	//PRUEBA operator==
	BST tree;
	tree.add(14);
	tree.add(10);
	tree.add(20);
	tree.add(5);
	tree.add(7);
	tree.add(12);
	tree.add(18);
	tree.add(25);
	tree.add(23);
	tree.add(22);
	tree.add(29);

	if (miArbol==tree) {
		cout << "SI" << endl;
	}
	else
		cout << "NO" << endl;

	//PRUEBA maxWidth()
	cout << "*****PRUEBA maxWidth()*****" << endl;
	cout << miArbol.maxWidth() << endl;

	//PRUEBA CopyConstructor
	cout << "*****PRUEBA CopyConstructor*****" << endl;
	BST nuevoBST(miArbol);
	nuevoBST.print(2);
	cout << endl;
}