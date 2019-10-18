// EstructuraBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
#include "BST.h"

int main()
{
	BST miArbol;
	/*miArbol.add(14);
	miArbol.add(10);
	miArbol.add(20);
	miArbol.add(5);
	miArbol.add(7);
	miArbol.add(12);
	miArbol.add(18);
	miArbol.add(25);
	miArbol.add(23);
	miArbol.add(22);
	miArbol.add(26);*/

	/*miArbol.add(15);
	miArbol.add(7);
	miArbol.add(19);
	miArbol.add(5);
	miArbol.add(10);
	miArbol.add(3);
	miArbol.add(17);
	miArbol.add(22); */
	miArbol.add(1);
	miArbol.add(2);
	miArbol.add(3);

	miArbol.print(2);
	cout << endl;
	cout << "Smaller than me " << miArbol.howManyAreSmallerThanME(10) << endl;

	cout << "One Child: " << miArbol.oneChild() << endl;

	/*
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
	tree.add(29); */
}