/* 
* DataMap.cpp
*
* Created: 15/01/2015 9:47:37
* Author: b.abm
*/


#include "DataMap.h"

DataMap::DataMap( const DataMap &c )
{
	delete measures;
	delete configs;

	// TODO !!!!!! map = c.map NO ES COPY CONSTRUCTOR!!!!!!
	//map = new LinkedList<String, String>(c.map);
	measures = c.measures;
	configs = c.configs;
}

bool DataMap::addMeasure(const String& key, const String& value)
{
	return add(key, value, measures);
}

bool DataMap::addConfig(const String& key, const String& value)
{
	return add(key, value, configs);
}

bool DataMap::removeMeasure(const String& key)
{
	return remove(key, measures);
}

bool DataMap::removeConfig(const String& key)
{
	return remove(key, configs);
}

String DataMap::lookupMeasure(const String& key)
{
	return lookup(key, measures);
}

String DataMap::lookupConfig(const String& key)
{
	return lookup(key, configs);
}

bool DataMap::emptyMap()
{
	delete measures;
	delete configs;
	measures = new DoublyLinkedList<String, String>();
	configs = new DoublyLinkedList<String, String>();
	return true;
}

DataMap& DataMap::operator=( const DataMap& c ) 
{
	measures = c.measures;
	configs = c.configs;
	return *this;
}

bool DataMap::add(const String& key, const String& value, DoublyLinkedList<String, String> *list)
{
	// list is not NULL
	Node<String, String>* node = new Node<String, String>(key, value);
	int size = list->getSize();  // initial size
	
	if (list->add(node) && size <= list->getSize())	// if added or updated
		return true;
	return false;
}

bool DataMap::remove(const String& key, DoublyLinkedList<String, String> *list)
{
	if (!list)
		return false;

	// list is not NULL
	int size = list->getSize();  // initial size
	if (list->remove(key) && size > list->getSize())
		return true;
	return false;
}

String DataMap::lookup(const String& key, DoublyLinkedList<String, String> *list)
{
	if (!list)
		return "Lista vacia NOT FOUND";

	// list is not NULL
	Node<String, String>* node = list->getNode(key);
	if (node)
		return node->value;
	return "NOT FOUND";
}

DoublyLinkedList<String, String>* DataMap::getList(const String& kind)
{
	if (kind.equals("config")) return configs;
	else if (kind.equals("measure")) return measures;
	else return NULL;
}