/* 
* LinkedList.h
*
* Created: 15/01/2015 10:35:53
* Author: b.abm
*/


#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "Node.h"

/** Generic Linked List where the Nodes are sorted by their key
 */
template<class K, class V>
class LinkedList
{
//variables
public:
	int size;
	Node<K,V>* root;
	Node<K,V>* last;
protected:
private:

//functions
public:
	/** Constructor
	 */
	LinkedList() { 	size=0; root=last=NULL; }
	
	/** Copy constructor
		@param a list
	 */
	LinkedList( const LinkedList& c );
	
	/** Copy assignment operator: Deep copy
		@param a list
		@return a new list
	 */
	LinkedList& operator=( const LinkedList& c );

	/** Destructor
	 */
	~LinkedList() { clear(); }
	
	/** Returns current size of LinkedList
		@return size
	 */
	int getSize() { return size; }		// TODO : not need since size is public
	
	/** Get the previous node where the node with the specified key should be
		@param key
		@return the previous node;
				if the list is empty, return NULL
				if the previous node goes before the root, return NULL
	 */
	Node<K,V>* getNode(const K& key);
	
	/** Add a new node in the correct place; and increment size
		If a node exists with the given key, update it with the value of the new node
		@param node
		@return the list after operation
	 */
	LinkedList* add(Node<K,V>* node);	// NO parameter by reference becasuse the function saves a pointer to the node
	
	/** Remove node by key and decrement size
		@param key 
		@return the list after operation
	 */
	LinkedList* remove(const K& key);

	// TODO not need
	V* getValue(const K& key) {
		Node<K,V>* prev;
		Node<K,V>* current;
		prev=current=root;

		while (current && current->key < key) {
			prev = current;
			current = current->next;
		}
		
		// Check if then current->key is equal or greater than the parameter key
		if (current && current->key == key) {
			return &(current->value);
		}
		return NULL;
	}
protected:
private:
	/** Adds a node in the end of the LinkedList; increment size
		@param the new node
		@return if success
	 */
	bool addLast(Node<K,V>* node);	// NO parameter by reference becasuse the function saves a pointer to the node
	
	/** Remove last node
		@return the list after operation
	 */
	LinkedList* pop();
	
	/** Remove first node
		@return the list after operation
	 */
	LinkedList* shift();
	
	/** Clear the entire Linked list
	 */
	void clear();
}; //LinkedList

/*
template<class K, class V>
LinkedList<K,V>::LinkedList()
{
	size=0;
	root=last=NULL;
}

template<class K, class V>
LinkedList<K,V>::~LinkedList()
{
	clear();
}

template<class K, class V>
int LinkedList<K,V>::getSize()
{
	return size;
}
*/


/*
template<class K, class V>
Node<K,V>* LinkedList<K,V>::getNode(const K& key)
{
	Node<K,V>* prev = NULL;
	Node<K,V>* current = root;

	while (current && current->key < key) {
		prev = current;
		current = current->next;
	}
	
	// Check if then current->key is equal or greater than the parameter key
	//if (current) {
	//	if (current->key == key)
	//		return current;
	//	// else, current->key > key
	//	return prev;
	//}
	if (current)
		return prev;

	// Else, the node should be the last or the list is empty
	return NULL;
}*/

/*
template<class K, class V>
//LinkedList<K,V>* LinkedList<K,V>::add(const Node<K,V>& node)
LinkedList<K,V>* LinkedList<K,V>::add(Node<K,V>* node)
{
	Node<K,V>* prev = getNode(node->key);

	if (prev) {
		if (prev->next && prev->next->key == node->key)
			// next of prev is the node with the key
			prev->next->value = node->value;
		else {
			// node should be the next of prev
			node->next = prev->next;
			prev->next = node;
			size++;
		}
	} else {
		if (size)



		// The node should be the last or the list is empty
		addLast(node);
	}
	
	//return true;
	return this;
}*/

template<class K, class V>
Node<K,V>* LinkedList<K,V>::getNode(const K& key)
{
	Node<K,V>* prev = NULL;
	Node<K,V>* current = root;

	if (!size) 
		return NULL;

	while (current && current->key < key) {
		prev = current;
		current = current->next;
	}

	return prev;
}

template<class K, class V>
//LinkedList<K,V>* LinkedList<K,V>::add(const Node<K,V>& node)
LinkedList<K,V>* LinkedList<K,V>::add(Node<K,V>* node)
{
	Node<K,V>* prev = getNode(node->key);

	if (prev) {
		if (prev->next && prev->next->key == node->key)
			// next of prev is the node with the key
			prev->next->value = node->value;
		else {
			// node should be the next of prev
			node->next = prev->next;
			prev->next = node;
			size++;
		}
	} else {
		// list is empty or the node should be before root
		node->next = root;
		root = node;
		size++;
	}
	
	return this;
}

template<class K, class V>
LinkedList<K,V>* LinkedList<K,V>::remove(const K& key)
{
	/*
	if (size) {
		if (key < root->key || key > last->key)
			return this;

		else if (key == root->key)
			return shift();

		else if (key == last->key)
			return pop();

		// else, key only could be in the midle of the list
		Node<K,V>* prev = getNode(key);
		Node<K,V>* toDelete = prev->next;
		
		if (toDelete && toDelete->key == key) {
			// toDelete node has the key
			prev->next = toDelete->next;
			delete toDelete;
			size--;
		}

		return this;
	}

	return this;
	*/


	if (size == 1) {
		if (key == root->key) shift();
	
	} else if (size > 1) {
		if (key == root->key) shift();
		else if (key == last->key) pop();
		else {
			// key only could be in the midle of the list (with 2 nodes at least)
			Node<K,V>* prev = getNode(key);
			Node<K,V>* toDelete;
			if (prev && (toDelete = prev->next) && toDelete->key == key) {
				// toDelete node has the key
				prev->next = toDelete->next;
				delete toDelete;
				size--;
			} 
		}
	}

	return this;

}

template<class K, class V>
//bool LinkedList<K,V>::addLast(const Node<K,V>& node)
bool LinkedList<K,V>::addLast(Node<K,V>* node)
{
	if (size) {
		// Already have elements inserted
		last->next = node;		// YOU ARE NOT ABLE TO DO last->next = *node !! because you can't take the address of a reference (DEPRECTATED)
		last = node;			// en una linea! last=last->next=node
	} else {
		// First element being inserted
		root=last=node;
	}
	
	size++;

	return true;
}

template<class K, class V>
LinkedList<K,V>* LinkedList<K,V>::pop()
{
	if (size == 1) {
		delete(root);
		root = NULL;
		last = NULL;
		size--;
	} else if (size > 1) {
		Node<K,V>* prev = getNode(last->key);
		delete last;
		prev->next = NULL;
		last = prev;
		size--;
	}
	
	return this;
}

template<class K, class V>
LinkedList<K,V>* LinkedList<K,V>::shift()
{
	if (size == 1) {
		pop();
	} else if (size > 1) {
		Node<K,V>* next = root->next;
		//V ret = root->data;
		delete(root);
		root = next;
		size --;
	} 

	return this;
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
	// First, ensure to clear all the list
	clear();

	this->root = c.root;
	this->last = c.last;
	this->size = c.size;
	return *this;
}

#endif //__LINKEDLIST_H__
