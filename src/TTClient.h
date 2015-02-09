/* 
* TTClient.h
*
* Created: 15/01/2015 9:51:30
* Author: b.abm
*/


#ifndef __TTCLIENT_H__
#define __TTCLIENT_H__

#include <Client.h>

class TTClient
{
//variables
public:
protected:
private:
	Client* client;
	const char* internalID;
    const char* server;
	const char* path;
	const int port;
//functions
public:
	/** Default constructor
	 */
	TTClient(Client& client, const char* internalID, const char* server, const char* path, const int port): port(port)
	{
		this->client = &client;
		this->internalID = internalID;
		this->server = server;
		this->path = path;
		//this->port = port;


		//this->client = client;
		//this->internalID = internalID;
		//this->server = server;				// strcpy(this->server, server);
		//this->path = path;
	}

	/** 
	 */
	void writeData(const String& key, const String& value, const String& kind)
	{  
		Serial.println("xxxxxxxxxxxxxxxxxxxxxx");
		Serial.println(key+" "+value+" "+kind);
		delay(3000);
		
		/*String kind = "GC";
		String key = "clave";
		String value = "valor";*/

		char outBuf[128];
	
	  	if (client->connect(server, port)) {
			Serial.println(F("making HTTP request..."));

			sprintf(outBuf,"POST %s HTTP/1.1", path);
			client->println(outBuf);
			sprintf(outBuf,"Host: %s", server);
			client->println(outBuf);
			client->println(F("Content-Type: application/x-www-form-urlencoded"));
			client->print(F("Content-Length: "));
			//client->println(strlen(internalID)+strlen(key)+strlen(value)+20);
			client->println(strlen(internalID)+key.length()+value.length()+20);
			client->println();

			sprintf(outBuf,"cadena=#%s,#3,%s,%s,0$", internalID, kind.c_str(), key.c_str(), value.c_str());
			client->println(outBuf);

			//client->print(F("cadena=#")); //8
			//client->print(internalID);
			//client->print(",#3,"+kind+","); //7
			//->print(key);
			//client->print(","); // 1
			//client->print(value);
			//client->println(F(",0$")); // 3
		}
	}

	/**
	 */
	void readData()
	{
		bool receiving=false;
		while (!receiving)
			receiving = client->available();

		while (client->available())
			Serial.print((char)client->read());		// TODO
		client->stop();
	}

	/**
	 */
	void parseData() {}
protected:
private:
}; 

#endif //__TTCLIENT_H__