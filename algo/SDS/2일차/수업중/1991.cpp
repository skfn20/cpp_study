#include<iostream>

using namespace std;

class Node{
public:
	char value;
	Node LeftChild, RightChild;
	Node(char value, char left, char right);
	void preOrder(Node* root);
	void inOrder(Node* root);
	void postOrder(Node* root);
};

Node::Node(char value, char left, char right)
{
	this->value =value;
	
	this->LeftChild.value=left;
	this->RightChild.value=right;
}

int main()
{
	
	return 0;
}
