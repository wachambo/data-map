/*
  Writes into the cloud a measure named “a”. “a”  is a reading from an analog port. 
  The other variable, “b”, is a configuration parameter you will be able to control it from the web site. 
  If it is 0, the board will switch off the pin number 10. If it is bigger, the pin will be switched on.
 */

#include <GSM.h>
#include <TTOpenDataMapStorageCloudProto0.h>

// APN data
#define GPRS_APN       "m2mkit.telefonica.com" // replace your GPRS APN
#define GPRS_LOGIN     "" // replace with your GPRS login
#define GPRS_PASSWORD  "" // replace with your GPRS password
#define INTERNAL_ID    "ARi48"	// replace with your internal id

// initialize the library instance
GPRS gprs;
GSM gsmAccess(false); // include a 'true' parameter for debug enabled
GSMClient theGSMClient;

// instantiate a data map for TT Open using Protocol Zero
TTOpenDataMapStorageCloudProto0 DM(theGSMClient, INTERNAL_ID, "s1.tts01.net", "/Stack/Receive/", 80);


const int b = 10;	// digital out pin
const int a = A1;  	// analog input pin
int aValue = 0;  	// variable to store the value coming from the analog input
int bValue = LOW;	// variable to store the digital output value

void setup() {
	// initialize serial communications at 9600 bps:
  	Serial.begin(9600);

  	// initialize digital pin 10 as an output.
  	pinMode(b, OUTPUT);
}

void loop() {
	// read the analog in value and map it to the range of the analog out:
	aValue = analogRead(a);
	aValue = map(aValue, 0, 1023, 0, 255);

	Serial.println("a: " + aValue);
	delay(1000);

	// put the datas in the Data Map
	// and set 'a' as measure and 'b' as configuation
	DM.add("a", String(aValue), "measure");
 	DM.add("b", String(bValue), "config");

 	// synchronize with the cloud
	DM.synch();

	// update the digital pin with the new configuration
	bValue = ((String)DM.lookup("b", "measure")).toInt();
	Serial.println("b: " + bValue);
	digitalWrite(b, (int)(bValue > 0));	// LOW if bValue==0, HIGH in other case
}
