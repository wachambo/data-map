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
		Serial.println(key+" "+value+" "+kind);
		delay(3000);

		//char outBuf[128];
	
	  	if (client->connect(server, port)) {
			Serial.println(F("making HTTP request..."));

			client->print(F("POST "));
			client->print(path);
			client->println(F(" HTTP/1.1"));
			client->print(F("Host: "));
			client->println(server);

			client->println(F("Content-Type: application/x-www-form-urlencoded"));
			client->print(F("Content-Length: "));
			client->println(strlen(internalID)+key.length()+value.length()+20);
			client->println();

			client->print(F("cadena=#"));
			client->print(internalID);
			client->print(F(",#3,"));
			client->print(kind);
			client->print(F(","));
			client->print(key);
			client->print(F(","));
			client->print(value);
			client->println(F(",0$"));
		} else 
    		Serial.println(F("Failed"));
	} 

	/**
	 */
	void readData()
	{
		bool receiving=false;
		while (!receiving)
			receiving = client->available();

		String response;
		getResponseBody(&response);
		Serial.print("--> ");
		Serial.println(response);
		if (response.length()) 
			parseData(response);
	}

	/** Gives the body of the chunked HTTP Response
	 */
	void getResponseBody(String* response_body) {
		bool isChunk = false;
		char char_in;
		String str_in = "";

		*response_body = "";

		while (client->available()) {
			char_in = (char)client->read();

			if (isChunk) {
				if (char_in == '\r' || char_in == '\n') str_in += char_in;
				else *response_body += char_in;

				if (str_in.endsWith("\r\n")) {
					isChunk = false;
					str_in = "";
				}
			} else if (char_in == '#') {
				isChunk = true;
				*response_body = "#";
			}
		}
		client->stop();
	}

	/** Given a string, 
		param[in/out]	str: string 
		param[out]		key
		param[out]		value		
	 */
	void parseData(String* str, String* key, String* value) {
		String split_sharp;
		String split_comma;

		split_sharp = getToken(str, '#');
		Serial.println(split_sharp);

		/*
		int pos = 0;
		do {
			split_comma = getToken(split_sharp, ',');
			Serial.println(split_comma);

			if (pos == 1)
			pos++;
		} while (split_comma.length());
		*/

		for (int pos = 0; pos < 4; pos++) {
			split_comma = getToken(split_sharp, ',');

			switch(pos) {
				case 1: if (split_comma.equals("GM")) return;	// we're only interested in GC"
				case 2: *key = split_comma; break;
				case 3: *value = split_comma; break;
				default: break;
			}
		}

		/*
		split_sharp = getToken(str, '#'))
		if ((split_comma = getToken(split_sharp, ',')) == "GM") {
			split_sharp.remove(0, split_comma.length());
			split_comma = getToken(split_sharp, ',');
		}

		
		str->remove(0, split_sharp->length());

		while (char_in = str.charAt(i))
			if (char_in == '#')
				token = str.substring(from, to);
			to++;
		*/
	}

	/** Given a string, return the first occurrence of the token if the string is splitted by the delimiter
		Remove the token and the delimiter in the original string
		param[in/out]	string
		param[in]		delimiter
		Return the token if exists, else NULL
	 */
	String getToken(String* str, const char delimiter) {
		String token;

		if (!str) 
			return "";

		int index = str->indexOf(delimiter, 0);
		//Serial.println(index);
		//delay(1000);
		if (index != -1) {
			token = str->substring(0, index);
			//Serial.println(token);
			*str = str->substring(index+1);
			//Serial.println(*str);
			return token;
		}
		return "";
	}
protected:
private:
}; 

#endif //__TTCLIENT_H__