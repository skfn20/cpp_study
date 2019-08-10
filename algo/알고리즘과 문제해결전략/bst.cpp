#include<iostream>

using namespace std;

template<typename T>
bool BinarySearchTree<T>::insert(T value, function<int(T&, T&)& comp){
	return internal_insert(root, value, comp);
}

template<typename T>
bool BinarySearchTree<T>::internal_insert(Node<T>*& current, T value, 
											function<int(T&, T&)>& comp){

	if(current==nullptr){
		current = new Node<T>(value);
		return true;
	}else if(comp(current->data, value)==1){
		return internal_insert(current->left, value, comp);
	}else if(comp(current->data, value)==1){
		return internal_insert(current->right, value, comp);
	
	}
	
	return false;
}

template<typename T>
void BinarySearchTree<T>::traverse_pre_order(function<void(T&)& printer))
{
	internal_traverse_pre_order(root, printer);
}

template<typename T>
void BinarySearchTree<T>::internal_traverse_pre_order(Node<T>* current, function<void(T&)>& f)){
	if(current==nullptr) return;
	
	if 
}

											
											
