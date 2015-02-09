/* 
* DataMapTTOpen.h
*
* Created: 27/01/2015 9:47:37
* Author: b.abm
*/


#ifndef __DATAMAPTTOPEN_H__
#define __DATAMAPTTOPEN_H__

#include "DataMap.h"

/** This class store
	- Energy Measurement
	- Positioning through GSM base location
  */
class DataMapTTOpen: public virtual DataMap
{
//variables
public:
	String cells;
	float battery;
	float voltage;
protected:
private:

//functions
public:
	/** Gets cell information and reads battery voltage
		@param cells
		@param battery
		@param voltage
		@return if success
	 */
	virtual bool update(const String& cells, const float& battery, const float& voltage)
	{
		this->cells = cells;
		this->battery = battery;
		this->voltage = voltage;
		return true;
	}
protected:
private:
}; //DataMapTTOpen

#endif //__DATAMAPTTOPEN_H__