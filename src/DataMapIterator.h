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
	DataMap *dm;
	Node<String, String> *itMeasures;	// iterator over measures list
	Node<String, String> *itConfigs;	// iterator over configs list
	
	// TODO : it and kind are NOT USED
	Node<String, String>* it;
	String kind;		// "measures" or "configs"

//functions
public:
	/** Constructor
	 */
	//DataMapIterator(): DataMap() , it(configs->root), kind(NULL) {}
	DataMapIterator(DataMap *dm) : dm(dm), itMeasures(NULL), itConfigs(NULL) {}

	/** Init iterators: iterators points to configs root and measures root
		@return if data map is not null
	 */
	bool init() 
	{
		if (dm) {
			itMeasures = dm->measures->root;
			itConfigs = dm->configs->root;
			return true
		}
		itMeasures = itConfigs = NULL;
		return false;
	}


	bool nextMeasure(String* key, String* value) { 
		//Serial.println((uint16_t)itMeasures, HEX);
		return next(key, value, itMeasures); 
		//Serial.println((uint16_t)itMeasures, HEX);
	}
	bool nextConfig(String* key, String* value) { return next(key, value, itConfigs); }
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
		@param[out] key of the next node
		@param[out] value of the next node
		@param[in/out] pointer to reference iterator
		@return if the next node exists
	 */
	bool next(String* key, String* value, Node<String, String> *&it)
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