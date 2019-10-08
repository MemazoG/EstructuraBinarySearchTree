// EstructuraBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "BST.h"
#include <iostream>
using namespace std;

int main()
{
	BST miArbol;
	miArbol.add(20);
	miArbol.add(50);
	miArbol.add(20);

	miArbol.add(5);
	miArbol.add(100);
	miArbol.add(60);
	miArbol.add(8);

	miArbol.print(1);
	miArbol.print(2);
	miArbol.print(3);


}