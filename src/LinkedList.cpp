/* 
* LinkedList.cpp
*
* Created: 15/01/2015 10:35:53
* Author: b.abm
*/
/*
#include "LinkedList.h"

template<class K, class V>
LinkedList<K,V>::LinkedList()
{
	size=0;
	root=last=NULL;
} //LinkedList

template<class K, class V>
LinkedList<K,V>::~LinkedList()
{
	clear();
} //~LinkedList

template<class K, class V>
int LinkedList<K,V>::getSize()
{
	return size;
}

template<class K, class V>
Node<K,V>* LinkedList<K,V>::getNode(const K& key)
{
	Node<K,V>* current, prev = root;

	while (current && current->key < key) {
		prev = current;
		current = current->next;
	}
	
	// Check if then current->key is equal or greater than the parameter key
	if (current) {
		if (current->key == key)
		return current;
		else // current->key > key
		return prev;
	}
	
	// Else, the node should be the last or the list is empty
	return NULL;
}

template<class K, class V>
LinkedList<K,V>* LinkedList<K,V>::add(const K& key, const V& value)
{
	//Node<K,V> *tmp = new Node<K,V>();
	Node<K,V> *prev = getNode(key);

	if (prev) {
		if (prev->key == key)
		// prev is the node with the key
		prev->value = value;
		else {
			// prev is the previous node
			
			//tmp->key = key;
			//tmp->value = value;
			//tmp->next = prev->next;
			//prev->next = tmp;
			prev->next = new Node<K,V>(key,value,prev->next);
			size++;
		}
	} else {
		// The node should be the last or the list is empty
		addLast(key,value);
	}
	
	//return true;
	return this;
}

template<class K, class V>
LinkedList<K,V>* LinkedList<K,V>::add(const Node<K,V>& node)
{
	//Node<K,V> *tmp = new Node<K,V>();
	Node<K,V> *prev = getNode(node.key);

	if (prev) {
		if (prev->key == node.key)
		// prev is the node with the key
		prev->value = node.value;
		else {
			// prev is the previous node
			
			//tmp->key = key;
			//tmp->value = value;
			//tmp->next = prev->next;
			//prev->next = tmp;
			prev->next = new Node<K,V>(node.key, node.value, prev->next);
			size++;
		}
	} else {
		// The node should be the last or the list is empty
		addLast(node.key, node.value);
	}
	
	//return true;
	return this;
}

template<class K, class V>
LinkedList<K,V>* LinkedList<K,V>::remove(const K& key)
{
	if (key >= last->key)
		//return V();
		return LinkedList<K,V>();

	if (key == root->key)
		return shift();
	
	if (key == last->key)
		return pop();

	Node<K,V> *tmp = getNode(key);
	Node<K,V> *toDelete = tmp->next;
	//V ret = toDelete->value;
	tmp->next = tmp->next->next;
	delete toDelete;
	size--;
	
	//return ret;
	return this;
}

template<class K, class V>
bool LinkedList<K,V>::addLast(const K& key, const V& value)
{
	//Node<K,V> *tmp = new Node<K,V>();
	//tmp->key = key;
	//tmp->value = value;
	//tmp->next = NULL;
	Node<K,V> *tmp(key,value);
	
	if (root) {
		// Already have elements inserted
		last->next = tmp;
		last = tmp;
	} else {
		// First element being inserted
		root = tmp;
		last = tmp;
	}
	
	size++;

	return true;
}

template<class K, class V>
LinkedList<K,V>* LinkedList<K,V>::pop()
{
	if (size <= 0)
		//return V();
		return LinkedList<K,V>();

	if (size >= 2) {
		Node<K,V> *tmp = getNode(last->key);
		//V ret = last->value;
		delete last;
		tmp->next = NULL;
		last = tmp;
		size--;
		//return ret;
	} else {	// Only one element
		//V ret = root->value;
		delete(root);
		root = NULL;
		last = NULL;
		size = 0;
		//return ret;
	}
	
	return this;
}

template<class K, class V>
LinkedList<K,V>* LinkedList<K,V>::shift()
{
	if (size <= 0)
		//return V();
		return LinkedList<K,V>();

	if (size > 1) 
	{
		Node<K,V> *next = root->next;
		//V ret = root->data;
		delete(root);
		root = next;
		size --;

		//return ret;
		return this;
	} else {
		// Only one left, then pop()
		return pop();
	}
}

template<class K, class V>
void LinkedList<K,V>::clear()
{
	Node<K,V>* tmp;
	while (root != NULL)
	{
		tmp=root;
		root=root->next;
		delete tmp;
	}
	last = NULL;
	size=0;
}

template<class K, class V>
LinkedList<K, V>::LinkedList(const LinkedList &c)
{
	// First, ensure to clear all the list
	clear();
	
	if (c.size <= 0) {
		root = last = NULL;
	} else {
		// At least one node
		Node<K,V>* current = c.root;
		Node<K,V>* copy(current->key, current->value);

		root = copy;
					
		while (current->next) {
			current = current->next;
			copy->next = new Node<K,V>(current->key, current->value);
			copy = copy->next;
		}
		last = current;
	}
		
	size = c.size;
}

template<class K, class V>
LinkedList<K,V>& LinkedList<K, V>::operator=(const LinkedList &c)
{
	this->root = c.root;
	this->last = c.last;
	this->size = c.size;
	return *this;
}
*/
