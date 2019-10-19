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
	miArbol.add(22);*/

	miArbol.add(10);		//			10
	miArbol.add(20);		//				20
	miArbol.add(30);		//			15		30
	miArbol.add(40);		//		12				40
	miArbol.add(15);
	miArbol.add(12);

// 	if (miArbol.isBalanced()) {
// 		cout << "BALANCEADO" << endl;
// 	}
// 	else {
// 		cout << "NO BALANCEADO" << endl;
// 	}

	cout << "DIAMETRO " << miArbol.diameter() << endl;
}