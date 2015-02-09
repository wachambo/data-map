/* 
* Node.h
*
* Created: 15/01/2015 9:51:30
* Author: b.abm
*/


#ifndef __NODE_H__
#define __NODE_H__

#ifndef NULL
	#define NULL 0
#endif

template<class K, class V>
class Node
{
//variables
public:
	// public attributes for simplicity
	K key;
	V value;
	Node<K,V>* prev;
	Node<K,V>* next;
protected:
private:

//functions
public:
	/** Default constructor
	 */
	Node() { next = prev = NULL; }

	/** Copy constructor
		@param a node
	 */
	Node( const Node& c ) : key(c.key), value(c.value), prev(c.prev), next(c.next) {}

	/** Copy assignment operator
		@param a node
		@return a new node
	 */
	//Node& operator=( const Node &c );

	/** Constructor with attributes
		@param key
		@param value
		@param ptr prev optional
		@param ptr next optional
	 */
	Node(const K& key, const V& value, Node<K,V>* prev = NULL, Node<K,V>* next = NULL) : 
		key(key), value(value), prev(prev), next(next) {}
	
	/** Destructor
	 */
	~Node() {}
protected:
private:
}; //Node

/*
template<class K, class V>
Node<K,V>::Node(const K& key, const V& value, Node<K,V>* ptrnext)
{
	this->key = key;
	this->value = value;
	this->next = ptrnext;
}*/

/*
template<class K, class V>
Node<K, V>::Node(const Node<K,V> &c)
{
	key = c.key;
	value = c.value;
	next = c.next;
}
*/

/*
template<class K, class V>
Node<K,V>& Node<K, V>::operator=(const Node<K,V> &c)
{
	this->key = c.key;
	this->value = c.value;
	this->next = c.next;
	return *this;
}
*/

#endif //__NODE_H__