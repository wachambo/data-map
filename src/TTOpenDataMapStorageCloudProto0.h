/* 
* TTOpenDataMapStorageCloudProto0.h
*
* Created: 27/01/2015 9:47:37
* Author: b.abm
*/


#ifndef __TTOPENDATAMAPSTORAGECLOUDPROTO0_H__
#define __TTOPENDATAMAPSTORAGECLOUDPROTO0_H__

#include "Storage.h"
#include "DataMapTTOpen.h"
#include "DataMapIterator.h"
#include "TTClient.h"


/** This class updates the map reading and writing from a cloud server
	using the Thinking Things Protocol
	In the future there will be versions for COAP, MQTT, Arduino Protocol...
 */
class TTOpenDataMapStorageCloudProto0: public Storage, public DataMapTTOpen, public DataMapIterator
{
//variables
public:
protected:
private:
	TTClient* ttclient;

//functions
public:
	TTOpenDataMapStorageCloudProto0(): Storage(), DataMapTTOpen(), DataMapIterator() {}
	/** Constructor
		@param map
		@param[in] server
		@param[in] path
		@param port
		@param client
	 */
	TTOpenDataMapStorageCloudProto0(Client& client, 
									const char* internalID, 
									const char* server, 
									const char* path, 
									const int port): Storage(), DataMapTTOpen(), DataMapIterator()
	{
		ttclient = new TTClient(client, internalID, server, path, port);
	}
	
	/** Destructor
	 */
	~TTOpenDataMapStorageCloudProto0()
	{
		delete ttclient;
	}

	/** Opens the socket, writes, reads, parses and updates the map
		@return if success
	 */
	virtual bool synch()
	{ 
		// First, gets cell information and reads battery voltage
		// TODO: HOW TO GET THESE PARAMS???
		String cells = "53434.452352, 523424.4234";
		float battery = 12.4;
		float voltage = 32.32;
		if (!update(cells, battery, voltage))
			return false;

		// Writes the map into the Cloud 
		String key;
		String value;
		String kind;
		if (first()) {
			while (next(&key, &value, &kind)) {
				// Write map to Cloud
 				ttclient->writeData(key, value, kind);
				
				//Read map from the Cloud
				String response = ttclient->readData();

				// Update the map
				while (response.length()) {
					ttclient->parseData(&response, &key, &value);	// TODO: deberia declara nuevas strigs key value???????

					if (key.equals("") && value.equals(""))
						continue;

					Serial.print("\n\n\n");
					Serial.println(key +"-"+ value);
					Serial.print("\n\n\n");
					add(key, value, "config");
				}
			}
		}

		return true;	// TODO always true?
	}
protected:
private:
}; //TTOpenDataMapStorageCloudProto0

#endif //__TTOPENDATAMAPSTORAGECLOUDPROTO0_H__