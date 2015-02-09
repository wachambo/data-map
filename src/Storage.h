/* 
*Storage.h
*
* Created: 27/01/2015 9:47:37
* Author: b.abm
*/


#ifndef __STORAGE_H__
#define __STORAGE_H__

/** Abstract class
	so it cannot be used to instantiate objects and serves only as an interface
 	If a subclass needs to be instantiated, it has to implement 'synch'
 */
class Storage
{
//variables
public:
protected:
private:

//functions
public:
	/** 
	 */
	virtual bool synch() { return false; }
protected:
private:
}; //Storage

#endif //__STORAGE_H__