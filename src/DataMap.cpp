/* 
* DataMap.cpp
*
* Created: 15/01/2015 9:47:37
* Author: b.abm
*/


#include "DataMap.h"

bool DataMap::add(const String& key, const String& value, const String& kind="measure")
{
	// What list?
	DoublyLinkedList<String, String>* list = getList(kind);
	if (!list)
		return false;

	// list is not NULL
	Node<String, String>* node = new Node<String, String>(key, value);
	int size = list->getSize();  // initial size
	
	if (list->add(node) && size <= list->getSize())	// if added or updated
		return true;
	return false;
}

bool DataMap::remove(const String& key, const String& kind="config")
{
	// What list?
	DoublyLinkedList<String, String>* list = getList(kind);
	if (!list)
		return false;

	// list is not NULL
	int size = list->getSize();  // initial size
	if (list->remove(key) && size > list->getSize())
		return true;
	return false;
}

String DataMap::lookup(const String& key, const String& kind="measure")
{
	/*
	TTOpenNode<String, String>* prev = map->getNode(key);
	
	if (prev) {
		if (prev->next && prev->next->key == key)
			return prev->next->value;
		return "NOT FOUND";
	} else {
		// list is empty or prev should be before root
		if (map->getSize() && map->root->key == key) 
			return map->root->value;
		return "NOT FOUND";
	}
	*/
	
	// What list?
	DoublyLinkedList<String, String>* list = getList(kind);
	if (!list)
		return "Lista vacia NOT FOUND";

	// list is not NULL
	Node<String, String>* node = list->getNode(key);
	if (node)
		return node->value;
	return "NOT FOUND";
}

bool DataMap::emptyMap()
{
	delete measures;
	delete configs;
	measures = new DoublyLinkedList<String, String>();
	configs = new DoublyLinkedList<String, String>();
	return true;
}

DataMap::DataMap( const DataMap &c )
{
	delete measures;
	delete configs;

	// TODO !!!!!! map = c.map NO ES COPY CONSTRUCTOR!!!!!!
	//map = new LinkedList<String, String>(c.map);
	measures = c.measures;
	configs = c.configs;
}

DataMap& DataMap::operator=( const DataMap& c ) 
{
	measures = c.measures;
	configs = c.configs;
	return *this;
}

DoublyLinkedList<String, String>* DataMap::getList(const String& kind)
{
	if (kind.equals("config")) return configs;
	else if (kind.equals("measure")) return measures;
	else return NULL;
}