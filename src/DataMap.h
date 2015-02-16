/* 
* DataMap.h
*
* Created: 15/01/2015 9:47:37
* Author: b.abm
*/


#ifndef __DATAMAP_H__
#define __DATAMAP_H__

#include "Arduino.h"
#include "DoublyLinkedList.h"

/** Internally stores objects two doubly linked lists
	- measures list
	- congigurations list
	Every node has two strings (key - value)
 */
class DataMap
{
friend class DataMapIterator;

//variables
public:
	DoublyLinkedList<String, String>* measures;
	DoublyLinkedList<String, String>* configs;
protected:
private:

//functions
public:
	/** Constructor
	 */
	DataMap() { 
		measures = new DoublyLinkedList<String, String>(); 
		configs = new DoublyLinkedList<String, String>(); 
	}

	/** Copy Constructor
	 */
	DataMap( const DataMap &c );
	
	/** Destructor
	 */
	virtual ~DataMap() { 
		delete measures; 
		delete configs;
	}

	/** Adds a new node to the measures list in the correct position
		@param key
		@param value
		@return if success
	 */
	bool addMeasure(const String& key, const String& value);

	/** Adds a new node to the config list in the correct position
		@param key
		@param value
		@return if success
	 */
	bool addConfig(const String& key, const String& value);
	
	/** Remove the node in the measures list with the key
		@param key
		@return if success
	 */
	bool removeMeasure(const String& key);

	/** Remove the node in the configs list with the key
		@param key
		@return if success
	 */
	bool removeConfig(const String& key);

	/** Look for the value related to the key in the measures list
		@param key
		@return the value; "" if not found
	 */
	String lookupMeasure(const String& key);

	/** Look for the value related to the key in the config list
		@param key
		@return the value; "" if not found
	 */
	String lookupConfig(const String& key);

	/** Resets the lists
		@return if success
	 */
	bool emptyMap();
	
	// this function can be override when inheriting
	virtual bool update() { return false; }

	// TODO : NOT USED
	// TODO me gustaria que fuera una funcion independiente de la clase, en un namespace? --> esta funcion al final no hace falta
	/** Copy the string in program memory (Flash) into a string in SRAM
	  @param[out] str is the string allocated in SRAM memory
	  @param[in] p_str is the string allocated in program memory (Flash)
	 */
	static void copy_flash (char* str, const char* p_str)
	{
		for (int i=0; char c = (char)pgm_read_byte(&p_str[i]); i++)
	      	//Serial.println(c);
			str[i] = c;
	}
protected:
	DataMap& operator=( const DataMap& c );
private:
	/** Adds a new node to the list in the correct position
		@param key
		@param value
		@param list
		@return if success
	 */
	//bool add(const String& key, const String& value, const String& kind);
	bool add(const String& key, const String& value, DoublyLinkedList<String, String> *list);

	/** Remove the node in the list with the key
		@param key
		@param list
		@return if success
	 */
	bool remove(const String& key, DoublyLinkedList<String, String> *list);

	/** Look for the value related to the key in the list
		@param key
		@param list
		@return the value; "" if not found
	 */
	//const String& lookup(const String& key);
	String lookup(const String& key, DoublyLinkedList<String, String> *list);

	/** Return measures or configs list depending on the parameter kind (measure/config)
		@param kind
		@return the list
	 */
	// TODO: NOT USED
	DoublyLinkedList<String, String>* getList(const String& kind);

}; //DataMap

#endif //__DATAMAP_H__