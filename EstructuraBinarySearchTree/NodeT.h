#pragma once
class NodeT {
private:
	int data;
	NodeT *left;
	NodeT *right;

public:
	NodeT(int data);
	int getData();
	void setData(int data);
	NodeT* getLeft();
	void setLeft(NodeT* left);
	NodeT* getRight();
	void setRight(NodeT* right);
};

NodeT::NodeT(int  data) {
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

int NodeT::getData() {
	return this->data;
}

void NodeT::setData(int data) {
	this->data = data;
}

NodeT* NodeT::getLeft() {
	return left;
}

void NodeT::setLeft(NodeT *left) {
	this->left = left;
}

NodeT* NodeT::getRight() {
	return this->right;
}

void NodeT::setRight(NodeT *right) {
	this->right = right;
}