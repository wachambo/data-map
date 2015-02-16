/* 
* DataMapIterator.h
*
* Created: 27/01/2015 9:47:37
* Author: b.abm
*/


#ifndef __DATAMAPITERATOR_H__
#define __DATAMAPITERATOR_H__

#include "DataMap.h"

/** This class adds to DataMap an iterator
  The iterator iterates over the config list and measures lista as a unique list
  First, starts at measures list, and when it fishes, continue with measures list
 */
//class DataMap;

class DataMapIterator //: public virtual DataMap
{
//variables
public:
protected:
private:
	static Node<String, String>* itMeasures;	// iterator over measures list
	static Node<String, String>* itConfigs;	// iterator over configs list
	
	// TODO : it and kind are NOT USED
	Node<String, String>* it;
	String kind;		// "measures" or "configs"

//functions
public:
	/** Constructor
	 */
	//DataMapIterator(): DataMap() , it(configs->root), kind(NULL) {}
	DataMapIterator(DataMap *dm) {
		if (dm) {
			itMeasures = dm->measures->root;
			itConfigs = dm->configs->root;
		} else itMeasures = itConfigs = NULL;
	}

	/** Reset iterator: iterator points to configs root, if any, else points to measures root
		@return if root node exists
	 */
		// TODO : not used
	/*bool first() 
	{
		DoublyLinkedList<String, String>* list;
		if ((it = configs->root)) {
			list = configs;
			kind = "GC";
		} else if ((it = measures->root)) {
			list = measures;
			kind = "GM";
		}

		return (list != NULL);
	}*/

	static bool nextMeasure(String* key, String* value) { return next(key, value, itMeasures); }
	static bool nextConfig(String* key, String* value) { return next(key, value, itConfigs); }
protected:
	/*DataMapIterator( const DataMapIterator &c ): DataMap(c) {
		//it = configs->root;
		itMeasures = measures->root;
		itConfigs = configs->root;
	}*/
	// Default behavior
	//DataMapIterator& operator=( const DataMapIterator& c );
private:
	/** Return key and value of the current node 
		And update the iterator to next node in the iteration
		(Remember the measures list goes after configurations list)
		@param[out] key of the next node
		@param[out] value of the next node
		@return if the next node exists
	 */
	/*
	bool next(String* key, String* value, String* kind)
	{
		if (it) {
			*key = it->key;
			*value = it->value;
			*kind = this->kind;
	
			// if it 
			if (it == configs->last) { 
				it = measures->root; 
				this->kind = "GM";
			} else it = it->next;
			return true;
		} 
		key = value = kind = NULL;
		return false;
	}*/

	static bool next(String* key, String* value, Node<String, String> *it)
	{
		if (it) {
			*key = it->key;
			*value = it->value;
			it = it->next;
			return true;
		}
		key = value = NULL;
		return false;
	}
}; //DataMapIterator

#endif //__DATAMAPITERATOR_H__





/*
private:
  Node<String, String>* it;

//functions
public:
  DataMapIterator(Node<String, String>* it) :it(it) {}
  DataMapIterator(const DataMapIterator& c) : it(c.it) {}
  DataMapIterator& operator++() {++it; return *this;}
  bool operator==(const DataMapIterator& c) {return it==c.it;}
  bool operator!=(const DataMapIterator& c) {return it!=c.it;}
  Node<String, String>& operator*() {return *it;}

  */