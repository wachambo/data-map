/* 
* DoublyLinkedList.h
*
* Created: 15/01/2015 10:35:53
* Author: b.abm
*/


#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

#include "Node.h"

/** Generic Doubly Linked List where the Nodes are sorted by their key
	previous node to root is NULL
	next node to last is NULL
 */
template<class K, class V>
class DoublyLinkedList
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
	DoublyLinkedList() { size=0; root=last=NULL; }
	
	/** Copy constructor
		@param a list
	 */
	DoublyLinkedList( const DoublyLinkedList& c );
	
	/** Copy assignment operator: Deep copy
		@param a list
		@return a new list
	 */
	DoublyLinkedList& operator=( const DoublyLinkedList& c );

	/** Destructor
	 */
	~DoublyLinkedList() { clear(); }
	
	/** Returns current size of DoublyLinkedList
		@return size
	 */
	int getSize() { return size; }		// TODO : not need since size is public
	
	/** Get the node with the key
		@param key
		@return the node with the key 
				if not exists return NULL
	 */
	Node<K,V>* getNode(const K& key);
	
	/** Add a new node in the correct place; and increment size
		If a node exists with the given key, update it with the value and kind of the new node
		@param node
		@return the list after operation
	 */
	DoublyLinkedList* add(Node<K,V>* node);	// NO parameter by reference becasuse the function saves a pointer to the node
	
	/** Remove node by key and decrement size
		@param key 
		@return the list after operation
	 */
	DoublyLinkedList* remove(const K& key);
protected:
private:
	/** Clear the entire Linked list
	 */
	void clear();
}; //DoublyLinkedList

template<class K, class V>
Node<K,V>* DoublyLinkedList<K,V>::getNode(const K& key)
{
	Node<K,V>* curr = root;
	while (curr && curr->key < key) 
		curr = curr->next;

	if (curr && curr->key == key)
		return curr;
	return NULL;
}

template<class K, class V>
DoublyLinkedList<K,V>* DoublyLinkedList<K,V>::add(Node<K,V>* node)
{
	if (!size) {
		// List is empty
		root = last = node;
		node->prev = node->next = NULL;
		size++;
	} else {
		// One node at least
		Node<K,V>* curr = root;
		while (curr && curr->key < node->key)
			curr = curr->next;

		if (!curr) {
			node->prev = last;
			last->next = node;
			last = node;
			node->next = NULL;
			size++;
		} else if (curr->key > node->key) {
			if (curr->prev) curr->prev->next = node;
			else root = node; // root == curr
			node->prev = curr->prev;
			node->next = curr;
			curr->prev = node;
			size++;
		} else	// curr->key == node->key
			curr->value = node->value;
	}

	return this;
}

template<class K, class V>
DoublyLinkedList<K,V>* DoublyLinkedList<K,V>::remove(const K& key)
{
	if (size) {
		// One node at least
		Node<K,V>* curr = root;
		while (curr && curr->key < key)
			curr = curr->next;

		if (curr && curr->key == key) {
			if (curr->prev) curr->prev->next = curr->next;
			// curr == root
			else root = root->next;

			if (curr->next) curr->next->prev = curr->prev;
			// curr == last
			else last = last->prev;

			size--;
		}
	}

	return this;
}

template<class K, class V>
void DoublyLinkedList<K,V>::clear()
{
	Node<K,V>* tmp;
	while (root) {
		tmp = root;
		root = root->next;
		delete tmp;
	}
	last = NULL;
	size = 0;
}

template<class K, class V>
DoublyLinkedList<K, V>::DoublyLinkedList(const DoublyLinkedList &c)
{
	// First, ensure to clear all the list
	clear();
	
	if (!c.size)
		root = last = NULL;
	else {
		// At least one node
		Node<K,V>* curr = c.root;
		Node<K,V>* copy = new Node<K,V>(curr->key, curr->value);

		root = copy;		
		while (curr = curr->next) {
			copy->next = new Node<K,V>(curr->key, curr->value, copy, NULL);
			copy = copy->next;
		}
		last = copy;
	}
		
	size = c.size;
}

template<class K, class V>
DoublyLinkedList<K,V>& DoublyLinkedList<K, V>::operator=(const DoublyLinkedList &c)
{
	// First, ensure to clear all the list
	clear();

	this->root = c.root;
	this->last = c.last;
	this->size = c.size;
	return *this;
}

#endif //__DOUBLYLINKEDLIST_H__
