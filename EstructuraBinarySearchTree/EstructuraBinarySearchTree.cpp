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


	//miArbol.print(1);

	vector<int> ancestros = miArbol.ancestors(23);

 	cout << "SIZE: " << ancestros.size() << endl;
 	for (int i = 0; i < ancestros.size(); i++) {
 		cout << ancestros[i] << " ";
	}
	cout << endl;

	cout << "NIVEL DEL n/a: " << miArbol.whatLevelAmI(666) << endl;

	cout << "PRINT POR NIVELES" << endl;
	miArbol.print(5);

	cout << endl;
	cout << "HEIGHT: " << miArbol.height() << endl;
}